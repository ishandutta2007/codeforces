#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M;
int board[5][5];
int E[5][5];
char str[1010];

int main(){
    scanf("%s", str+1);
    for (int i=1; str[i]; i++){
        if (str[i] == '1'){
            bool tf = true;
            for (int i=1; i<=4; i++){
                if (!tf) break;
                for (int j=1; j<4; j++){
                    if (!board[i][j] && !board[i][j+1]){
                        board[i][j] = board[i][j+1] = 1;
                        printf("%d %d\n", i, j);
                        tf = false;
                        break;
                    }
                }
            }
        }
        else{
            bool tf = true;
            for (int i=1; i<=4; i++){
                if (!tf) break;
                for (int j=1; j<4; j++){
                    if (!board[j][i] && !board[j+1][i]){
                        board[j][i] = board[j+1][i] = 1;
                        printf("%d %d\n", j, i);
                        tf = false;
                        break;
                    }
                }
            }
        }
        for (int i=1; i<=4; i++) for (int j=1; j<=4; j++) E[i][j] = 0;
        for (int i=1; i<=4; i++){
            if (board[i][1] && board[i][2] && board[i][3] && board[i][4]) E[i][1] = E[i][2] = E[i][3] = E[i][4] = 1;
            if (board[1][i] && board[2][i] && board[3][i] && board[4][i]) E[1][i] = E[2][i] = E[3][i] = E[4][i] = 1;
        }
        for (int i=1; i<=4; i++) for (int j=1; j<=4; j++) if (E[i][j]) board[i][j] = 0;
    }
    return 0;
}