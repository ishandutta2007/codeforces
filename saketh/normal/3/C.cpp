#include <iostream>
using namespace std;

char b[3][3], t;
int X, O;

bool win(){
    for(int i=0; i<3; i++)
        if(b[i][0]!='.' && b[i][0]==b[i][1] && b[i][1]==b[i][2])
            return true;
    for(int j=0; j<3; j++)
        if(b[0][j]!='.' && b[0][j]==b[1][j] && b[1][j]==b[2][j])
            return true;
    if(b[1][1]=='.') return false;
    return (b[0][0]==b[1][1] && b[1][1]==b[2][2])
        || (b[0][2]==b[1][1] && b[1][1]==b[2][0]);
}

int main(){
    for(int i=0; i<9; i++){
        cin >> t;
        b[i/3][i%3] = t;
        if(t == 'X') X++;
        if(t == '0') O++;
    }

    if(O>X || X-O>1){ cout << "illegal" << endl; return 0; }
    if(win()){
        char l = (X>O)?'X':'0';
        bool valid = false;

        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(b[i][j]==l){
                    b[i][j] = '.';
                    valid |= !win();
                    b[i][j] = l;
                }

        if(!valid) cout << "illegal" << endl;
        else if(l=='X') cout << "the first player won" << endl;
        else cout << "the second player won" << endl;
        return 0;
    }    

    if(O+X == 9) cout << "draw" << endl;
    else if(O==X) cout << "first" << endl;
    else cout << "second" << endl;

    return 0;
}