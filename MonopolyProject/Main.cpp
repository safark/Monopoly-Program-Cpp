#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include<map>

using namespace std;
class Player {
public:
    string playerName;
    int playerNumber;
    int playerMoney;
    int boardPosition;
};
class Property {
public:
    string propertyName;
    int propertyCost;
    int rentOwed;
    int propertyOwner;
    int boardPosition;
};

void initializeProperties(vector<Property>& properties);
void initializePlayers(int playerCount, vector<Player>& players, Player player);
void rollDice(vector<Player>& players, vector<Property>& properties);
void saveGame(vector<Player>& players, vector<Property>& properties);
void loadGame(vector<Player>& players, vector<Property>& properties);

int main() {

    // Intro
    srand(time(0));
    int option;
    cout << "Hello! Welcome to the world of Safopoly! \n";
    cout << "Would you like to start a new game(1) or load a previous game(2)? ";
    cin >> option;

    while (option > 2 || option < 1) {
        cout << "ERROR please pick start a new game(1) or load a previous game(2) ";
        cin >> option;
    }

    vector<Player> players;
    vector<Property> properties;

    if (option == 1) {
        int playerCount;
        cout << "How many players will be participating? ";
        cin >> playerCount;

        while (playerCount > 8 || playerCount < 2) {
            cout << "Sorry, the max limit of players is 8 and minimum is 2. Please input how many players will be participating: ";
            cin >> playerCount;
        }

        // Adding players
        Player player;
        initializePlayers(playerCount, players, player);

        // Properties
        initializeProperties(properties);

        //rolling dice simulator
        //moving
        rollDice(players, properties);

    }
    else if (option == 2) {


        loadGame(players, properties);

        //play game
        rollDice(players, properties);


    }


    return 0;
}

void saveGame(vector<Player>& players, vector<Property>& properties) {
    string theFileName;
    cout << "What do you want to name your save? ";
    cin >> theFileName;
    ofstream saveFile(theFileName + ".txt");

    if (saveFile.is_open()) {
        // Save player information
        saveFile << players.size() << "\n";
        for (Player& player : players) {
            saveFile << player.playerName << "\n"
                << player.playerNumber << "\n"  // Save playerNumber
                << player.playerMoney << "\n"
                << player.boardPosition << "\n";
        }

        // Save property information
        for (Property prop : properties) {
            saveFile << prop.propertyName << "\n" << prop.propertyCost << "\n" << prop.rentOwed
                << "\n" << prop.propertyOwner << "\n" << prop.boardPosition << "\n";
        }

        saveFile.close();
        cout << "Game saved successfully!\n";
    }
    else {
        cout << "Error: Unable to save the game.\n";
    }
}
void loadGame(vector<Player>& players, vector<Property>& properties) {
    string fileName;
    cout << "Enter the name of the save file (without extension): ";
    cin >> fileName;

    ifstream loadFile(fileName + ".txt");

    if (loadFile.is_open()) {
        int playerCount;
        loadFile >> playerCount;
        players.resize(playerCount);

        // Load player information
        for (int i = 0; i < playerCount; ++i) {
            loadFile >> players[i].playerName >> players[i].playerNumber >> players[i].playerMoney >> players[i].boardPosition;
        }

        // Load property information
        properties.resize(28);
        loadFile.ignore();  // Ignore the newline character after player count
        for (int i = 0; i < 28; ++i) {
            // Read the property name until a newline character is encountered
            getline(loadFile, properties[i].propertyName);

            // Read the numerical values
            loadFile >> properties[i].propertyCost >> properties[i].rentOwed
                >> properties[i].propertyOwner >> properties[i].boardPosition;

            // Consume the newline character after each line
            loadFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        loadFile.close();
        cout << "Game loaded successfully!\n";
    }
    else {
        cout << "Error: Unable to load the game. Make sure the file exists.\n";
    }
}
void initializeProperties(vector<Property>& properties) {

    properties.resize(28);

    for (int i = 0; i < 28; i++) {
        properties[i].propertyOwner = 0;
    }

    properties[0].propertyCost = 60;
    properties[0].propertyName = "Mediterranean Avenue";
    properties[0].rentOwed = 2;
    properties[0].boardPosition = 2;

    properties[1].propertyCost = 60;
    properties[1].propertyName = "Baltic Avenue";
    properties[1].rentOwed = 4;
    properties[1].boardPosition = 4;

    // Light Blue Properties
    properties[2].propertyCost = 100;
    properties[2].propertyName = "Oriental Avenue";
    properties[2].rentOwed = 6;
    properties[2].boardPosition = 7;

    properties[3].propertyCost = 100;
    properties[3].propertyName = "Vermont Avenue";
    properties[3].rentOwed = 6;
    properties[3].boardPosition = 9;

    properties[4].propertyCost = 120;
    properties[4].propertyName = "Connecticut Avenue";
    properties[4].rentOwed = 8;
    properties[4].boardPosition = 10;

    // Pink Properties
    properties[5].propertyCost = 140;
    properties[5].propertyName = "St. Charles Place";
    properties[5].rentOwed = 10;
    properties[5].boardPosition = 12;

    properties[6].propertyCost = 140;
    properties[6].propertyName = "States Avenue";
    properties[6].rentOwed = 10;
    properties[6].boardPosition = 14;

    properties[7].propertyCost = 160;
    properties[7].propertyName = "Virginia Avenue";
    properties[7].rentOwed = 12;
    properties[7].boardPosition = 15;

    // Orange Properties
    properties[8].propertyCost = 180;
    properties[8].propertyName = "St. James Place";
    properties[8].rentOwed = 14;
    properties[8].boardPosition = 17;

    properties[9].propertyCost = 180;
    properties[9].propertyName = "Tennessee Avenue";
    properties[9].rentOwed = 14;
    properties[9].boardPosition = 19;

    properties[10].propertyCost = 200;
    properties[10].propertyName = "New York Avenue";
    properties[10].rentOwed = 16;
    properties[10].boardPosition = 20;

    // Red Properties
    properties[11].propertyCost = 220;
    properties[11].propertyName = "Kentucky Avenue";
    properties[11].rentOwed = 18;
    properties[11].boardPosition = 22;

    properties[12].propertyCost = 220;
    properties[12].propertyName = "Indiana Avenue";
    properties[12].rentOwed = 18;
    properties[12].boardPosition = 24;

    properties[13].propertyCost = 240;
    properties[13].propertyName = "Illinois Avenue";
    properties[13].rentOwed = 20;
    properties[13].boardPosition = 25;

    // Yellow Properties
    properties[14].propertyCost = 260;
    properties[14].propertyName = "Atlantic Avenue";
    properties[14].rentOwed = 22;
    properties[14].boardPosition = 27;

    properties[15].propertyCost = 260;
    properties[15].propertyName = "Ventnor Avenue";
    properties[15].rentOwed = 22;
    properties[15].boardPosition = 28;

    properties[16].propertyCost = 280;
    properties[16].propertyName = "Marvin Gardens";
    properties[16].rentOwed = 24;
    properties[16].boardPosition = 30;

    // Green Properties
    properties[17].propertyCost = 300;
    properties[17].propertyName = "Pacific Avenue";
    properties[17].rentOwed = 26;
    properties[17].boardPosition = 32;

    properties[18].propertyCost = 300;
    properties[18].propertyName = "North Carolina Avenue";
    properties[18].rentOwed = 26;
    properties[18].boardPosition = 33;

    properties[19].propertyCost = 320;
    properties[19].propertyName = "Pennsylvania Avenue";
    properties[19].rentOwed = 28;
    properties[19].boardPosition = 35;

    // Dark Blue Properties
    properties[20].propertyCost = 350;
    properties[20].propertyName = "Park Place";
    properties[20].rentOwed = 35;
    properties[20].boardPosition = 38;

    properties[21].propertyCost = 400;
    properties[21].propertyName = "Boardwalk";
    properties[21].rentOwed = 50;
    properties[21].boardPosition = 40;

    // Utilities
    properties[22].propertyCost = 150;
    properties[22].propertyName = "Electric Company";
    properties[22].rentOwed = 25;
    properties[22].boardPosition = 13;

    properties[23].propertyCost = 150;
    properties[23].propertyName = "Water Works";
    properties[23].rentOwed = 25;
    properties[23].boardPosition = 29;

    // Railroads
    properties[24].propertyCost = 200;
    properties[24].propertyName = "Reading Railroad";
    properties[24].rentOwed = 25;
    properties[24].boardPosition = 6;

    properties[25].propertyCost = 200;
    properties[25].propertyName = "Pennsylvania Railroad";
    properties[25].rentOwed = 25;
    properties[25].boardPosition = 16;

    properties[26].propertyCost = 200;
    properties[26].propertyName = "B. & O. Railroad";
    properties[26].rentOwed = 25;
    properties[26].boardPosition = 26;

    properties[27].propertyCost = 200;
    properties[27].propertyName = "Short Line";
    properties[27].rentOwed = 25;
    properties[27].boardPosition = 36;


}

void initializePlayers(int playerCount, vector<Player>& players, Player player) {
    for (int i = 0; i < playerCount; i++) {
        players.push_back(player);

        cout << "What is player " << 1 + i << "'s name? ";
        cin >> players[i].playerName;
        players[i].playerName;
        players[i].playerMoney = 1500;
        players[i].playerNumber = i + 1;
        players[i].boardPosition = 1;
    }
}


void rollDice(vector<Player>& players, vector<Property>& properties) {

    // Continue playing while at least one player has positive money while atleast one player is positive money
    while (count_if(players.begin(), players.end(), [](const Player& player) { return player.playerMoney > 0; }) > 1) {

        // Iterate through each player's turn

        for (Player& player : players) {

            // Make them pay if they are in jail 
            if (player.boardPosition == 31) {
                cout << "You are in jail. You will now pay $50 to get out. \n";

                player.boardPosition = 11;
                player.playerMoney -= 50;
            }
            // Check if the player is bankrupt
            if (player.playerMoney <= 0) {
                cout << player.playerName << " is bankrupt!\n";
                for (Property& prop : properties) {
                    if (prop.propertyOwner == player.playerNumber) {
                        prop.propertyOwner = 0;
                    }
                }
            }


            else {
                // Prompt the player to roll the dice

                cout << "\n" << player.playerName << ", press 1 to roll the dice, 2 to save and exit. \n";
                int choice;
                cin >> choice;

                if (choice == 1) {

                    int dice1 = rand() % 6 + 1;
                    int dice2 = rand() % 6 + 1;
                    cout << "You rolled: " << dice1 << " and " << dice2 << endl;

                    // Calculate the total moves based on the dice rolls
                    int moves = dice1 + dice2;
                    player.boardPosition += moves;

                    // Ensure the player's position is within the board limit (1 to 40)
                    if (player.boardPosition > 40) {
                        // Reset the position to the appropriate value within the board
                        player.boardPosition -= 40;
                        //go money
                        cout << "You passed go! Here's your $200\n";
                        player.playerMoney += 200;
                        cout << "You now have $" << player.playerMoney << endl;
                    }

                    if (player.boardPosition == 31) {
                        cout << "GO DIRECTLY TO JAIL. DO NOT PASS GO, DO NOT COLLECT $200 \n";
                    }

                    cout << " New Position: " << player.boardPosition - 1 << endl;

                    for (Property& prop : properties) {

                        //Free spaces
                        if (player.boardPosition == 3 || player.boardPosition == 5 || player.boardPosition == 8 || player.boardPosition == 18 || player.boardPosition == 21 ||
                            player.boardPosition == 23 || player.boardPosition == 34 || player.boardPosition == 37 || player.boardPosition == 39) {
                            cout << "Free space \n";
                            break;
                        }


                        if (player.boardPosition == prop.boardPosition) {

                            cout << "You have landed on " << prop.propertyName << endl;

                            if (prop.propertyOwner != player.playerNumber && prop.propertyOwner != 0) {
                                player.playerMoney -= prop.rentOwed;


                                //subtract money from one player and add it to the other player by making a pointer of Player 
                                Player* owner = nullptr;
                                for (Player& findPlay : players) {
                                    if (findPlay.playerNumber == prop.propertyOwner) {
                                        owner = &findPlay;
                                        break;
                                    }
                                }

                                // Add rent to the property owner
                                if (owner != nullptr) {
                                    owner->playerMoney += prop.rentOwed;
                                    cout << owner->playerName << " owns this property! You owe them: $" << prop.rentOwed << endl;
                                    cout << "$" << prop.rentOwed << " has been paid  to " << owner->playerName << ".New balance of " << owner->playerName << " is $" << owner->playerMoney << endl;
                                    cout << "You now have $" << player.playerMoney << endl;
                                }

                            }



                            if (prop.propertyOwner == 0) {
                                int buyProp;
                                cout << prop.propertyName << " is for sale,it costs $" << prop.propertyCost << endl;
                                cout << "Would you like to buy this property? (1 for yes 2 for no) \n";
                                cin >> buyProp;
                                while (buyProp != 1 && buyProp != 2) {
                                    cout << "Invalid option \n";
                                    cout << "Would you like to buy this property? (1 for yes 2 for no) " << endl;
                                    cin >> buyProp;

                                }

                                if (buyProp == 1) {

                                    int theoretical = player.playerMoney - prop.propertyCost;

                                    if (theoretical > 0) {
                                        prop.propertyOwner = player.playerNumber;
                                        player.playerMoney -= prop.propertyCost;
                                        cout << "You have $" << player.playerMoney << endl;
                                    }
                                    if (theoretical < 0) {
                                        cout << "You cannot afford this property. \n";
                                    }


                                }
                                else if (buyProp == 2) {

                                    break;
                                }

                            }

                        }

                    }


                    int doubleCounter = 0;
                    // Check if the player rolled a double


                    while (dice1 == dice2) {
                        doubleCounter++;

                        if (doubleCounter == 3) {
                            cout << "You rolled a double 3 times in a row. You are going to jail.\n";
                            player.boardPosition = 11;
                            break;

                        }
                        else {
                            cout << "\nYOU ROLLED A DOUBLE! Press 1 to roll again: ";
                            int rollDice;
                            cin >> rollDice;
                            dice1 = rand() % 6 + 1;
                            dice2 = rand() % 6 + 1;
                            cout << "You rolled: " << dice1 << " and " << dice2 << endl;

                            // Calculate the total moves based on the dice rolls
                            int moves = dice1 + dice2;
                            player.boardPosition += moves;

                            // Ensure the player's position is within the board limit (1 to 40)
                            if (player.boardPosition > 40) {
                                // Reset the position to the appropriate value within the board
                                player.boardPosition -= 40;
                                //go money
                                cout << "You passed go! Here's your $200\n";
                                player.playerMoney += 200;
                                cout << "You now have $" << player.playerMoney << endl;
                            }

                            if (player.boardPosition == 31) {
                                cout << "GO DIRECTLY TO JAIL. DO NOT PASS GO, DO NOT COLLECT $200 \n";
                            }

                            cout << " New Position: " << player.boardPosition - 1 << endl;





                            for (Property& prop : properties) {

                                //Free spaces
                                if (player.boardPosition == 3 || player.boardPosition == 5 || player.boardPosition == 8 || player.boardPosition == 11 || player.boardPosition == 18 || player.boardPosition == 21 ||
                                    player.boardPosition == 23 || player.boardPosition == 34 || player.boardPosition == 37 || player.boardPosition == 39) {
                                    cout << "Free space \n";
                                    break;
                                }

                                if (player.boardPosition == prop.boardPosition) {

                                    cout << "You have landed on " << prop.propertyName << endl;

                                    if (prop.propertyOwner != player.playerNumber && prop.propertyOwner != 0) {
                                        player.playerMoney -= prop.rentOwed;


                                        //subtract money from one player and add it to the other player by making a pointer of Player 
                                        Player* owner = nullptr;
                                        for (Player& findPlay : players) {
                                            if (findPlay.playerNumber == prop.propertyOwner) {
                                                owner = &findPlay;
                                                break;
                                            }
                                        }

                                        // Add rent to the property owner
                                        if (owner != nullptr) {
                                            owner->playerMoney += prop.rentOwed;
                                            cout << owner->playerName << " owns this property! You owe them: $" << prop.rentOwed << endl;
                                            cout << "$" << prop.rentOwed << " has been paid  to " << owner->playerName << ".New balance of " << owner->playerName << " is $" << owner->playerMoney << endl;
                                            cout << "You now have $" << player.playerMoney << endl;
                                        }

                                    }


                                    if (prop.propertyOwner == 0) {
                                        int buyProp;
                                        cout << prop.propertyName << " is for sale,it costs $" << prop.propertyCost << endl;
                                        cout << "Would you like to buy this property? (1 for yes 2 for no) \n";
                                        cin >> buyProp;
                                        while (buyProp != 1 && buyProp != 2) {
                                            cout << "Invalid option \n";
                                            cout << "Would you like to buy this property? (1 for yes 2 for no) " << endl;
                                            cin >> buyProp;

                                        }

                                        if (buyProp == 1) {

                                            int theoretical = player.playerMoney - prop.propertyCost;

                                            if (theoretical > 0) {
                                                prop.propertyOwner = player.playerNumber;
                                                player.playerMoney -= prop.propertyCost;
                                                cout << "You have $" << player.playerMoney << endl;
                                            }
                                            if (theoretical < 0) {
                                                cout << "You cannot afford this property. \n";
                                            }


                                        }
                                        else if (buyProp == 2) {

                                            break;
                                        }

                                    }

                                }

                            }
                        }
                    }
                }
                else if (choice == 2) {
                    // Player chose to save the game
                    saveGame(players, properties);
                    cout << "Game saved!\n";
                    return;
                }




                // Check if the player is bankrupt after the move
                if (player.playerMoney <= 0) {
                    cout << player.playerName << " is bankrupt!!\n";
                }
            }
        }

        // Remove bankrupt players from the game
        players.erase(remove_if(players.begin(), players.end(), [](Player& player) {
            return player.playerMoney <= 0;
            }), players.end());
    }

    // Display the winner of the game

    if (!players.empty()) {


        cout << players[0].playerName << " is the winner!\n";
        saveGame(players, properties);
    }


}









