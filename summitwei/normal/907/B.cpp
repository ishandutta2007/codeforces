#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;


int convToBoard(int rowcol){
    if(rowcol >= 7){
        return rowcol+1;
    } else if(rowcol <= 3){
        return rowcol-1;
    } else{
        return rowcol;
    }
}

//findterritory should output a pair from (0, 0) to (2, 2)
pii findTerritory(int inputRow, int inputCol){
    return make_pair((inputRow-1)%3, (inputCol-1)%3);
}

int main(){
    vector<vector<char>> board(11);
    for(int i=0; i<11; i++){
        board[i].assign(11, ' ');
    }
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin >> board[convToBoard(i)][convToBoard(j)];
        }
    }

    //we have empty things at 3 and 7

    int A, B;
    cin >> A >> B;
    //A = convToBoard(A);
    //B = convToBoard(B);
    pii territory = findTerritory(A, B);
    int side1 = territory.first*3;
    int side2 = territory.second*3;
    //cout << side1 << " " << side2 << "\n";

    int hasBeenFound = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[convToBoard(side1+i+1)][convToBoard(side2+j+1)] == '.'){
                board[convToBoard(side1+i+1)][convToBoard(side2+j+1)] = '!';
                hasBeenFound = true;
            } /*else if(board[convToBoard(side1+i+1)][convToBoard(side2+j+1)] == ' '){
                //cout << "SOMETHING DONE BROKE";
            }*/
        }
    }

    if(!hasBeenFound){
        for(int i=0; i<11; i++){
            for(int j=0; j<11; j++){
                if(board[i][j] == '.'){
                    board[i][j] = '!';
                }
            }
        }
    }

    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}