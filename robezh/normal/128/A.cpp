#include<cstdio>
#include<iostream>
using namespace std;

char c[8][8];
int dp[10][8][8];
int dx[9] = {1,1,1,0,-1,-1,-1,0,0};
int dy[9] = {1,0,-1,-1,-1,0,1,1,0};


bool inbound(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void next_state() {
    for(int i = 7; i >= 0; i--) {
        for(int j = 0; j < 7; j++) {
            if(c[i][j] == 'S') {
                if(i != 7) c[i+1][j] = 'S';
                c[i][j] = '.';
                //cout << c[i][j];
            }
        }
    }
}



int main() {
    dp[0][7][0] = 1;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> c[i][j];
        }
    }
//    int t = 8;
//    while(t--) {
//        next_state();
//        for(int i = 0; i < 8; i++) {
//            for(int j = 0; j < 8; j++) {
//                cout << c[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    for(int p = 1; p <= 8; p++) {
        for(int d = 0; d < 9; d++) {
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if(!dp[p-1][i][j]) continue;
                    int nx = i + dx[d], ny = j + dy[d];
                    if(inbound(nx, ny) && c[nx][ny] != 'S') {
                        dp[p][nx][ny] = 1;
                    }
                }
            }
        }
        next_state();
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(c[i][j] == 'S') {
                    dp[p][i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(dp[8][i][j]) return !printf("WIN");
        }
    }
    return !printf("LOSE");
}