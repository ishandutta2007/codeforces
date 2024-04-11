#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int N, K;
long long D[1010][2020][4], ans;

int main(){
    scanf("%d %d", &N, &K);
    D[1][1][0] = D[1][1][3] = D[1][2][1] = D[1][2][2] = 1;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=2*i; j++){
            D[i+1][j][0] = (D[i+1][j][0] + D[i][j][0]) % MOD;
            D[i+1][j][0] = (D[i+1][j][0] + D[i][j][1]) % MOD;
            D[i+1][j][0] = (D[i+1][j][0] + D[i][j][2]) % MOD;
            D[i+1][j+1][0] = (D[i+1][j+1][0] + D[i][j][3]) % MOD;

            D[i+1][j+1][1] = (D[i+1][j+1][1] + D[i][j][0]) % MOD;
            D[i+1][j][1] = (D[i+1][j][1] + D[i][j][1]) % MOD;
            D[i+1][j+2][1] = (D[i+1][j+2][1] + D[i][j][2]) % MOD;
            D[i+1][j+1][1] = (D[i+1][j+1][1] + D[i][j][3]) % MOD;

            D[i+1][j+1][2] = (D[i+1][j+1][2] + D[i][j][0]) % MOD;
            D[i+1][j+2][2] = (D[i+1][j+2][2] + D[i][j][1]) % MOD;
            D[i+1][j][2] = (D[i+1][j][2] + D[i][j][2]) % MOD;
            D[i+1][j+1][2] = (D[i+1][j+1][2] + D[i][j][3]) % MOD;

            D[i+1][j+1][3] = (D[i+1][j+1][3] + D[i][j][0]) % MOD;
            D[i+1][j][3] = (D[i+1][j][3] + D[i][j][1]) % MOD;
            D[i+1][j][3] = (D[i+1][j][3] + D[i][j][2]) % MOD;
            D[i+1][j][3] = (D[i+1][j][3] + D[i][j][3]) % MOD;
        }
    }
    ans = (D[N][K][0] + D[N][K][1] + D[N][K][2] + D[N][K][3]) % MOD;
    printf("%I64d\n", ans);
    return 0;
}