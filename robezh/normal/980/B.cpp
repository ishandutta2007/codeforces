#include<bits/stdc++.h>
using namespace std;

int n,k;
char c[4][105];
int dp[2][4][105];

int main(){
    cin >> n >> k;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++) c[i][j] = '.';
    }

    cout << "YES\n";
    if(k % 2 == 0){
        for(int i = 1; i < 1+k/2; i++){
            c[1][i] = c[2][i] = '#';
        }
    }
    else if(k <= (n-2)){
        for(int i = n/2 - k/2; i <= n/2 + k/2; i++){
            c[1][i] = '#';
        }
    }
    else{
        for(int i = 1; i < n-1; i++){
            c[1][i] = '#';
        }
        c[2][1] = c[2][n-2] = '#';
        for(int i = 2; i < 2 + (k-(n-2)-2); i++){
            c[2][i] = '#';
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++) cout << c[i][j];
        cout << endl;
    }

}