#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 205, mod = (int)1e9 + 7;

int n;
int a[11];

ll dp[11][N];
int C[N][N];



int main() {
    for(int i = 0; i < N; i++) C[i][0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
    }
    cin >> n;
    bool nz = false;
    for(int i = 0; i < 10; i++) cin >> a[i], nz |= (a[i] != 0);
    dp[10][0] = 1;
    for(int i = 9; i >= 0; i--) {
        for(int j = 0; j + a[i] <= n; j++) {
            for(int add = a[i]; j + add <= n; add++) {
                if(i != 0) dp[i][j+add] += dp[i+1][j] * C[j+add][j] % mod;
                else {
                    if(j == 0) continue;
                    else dp[i][j+add] += dp[i+1][j] * C[j+add-1][j-1] % mod;
                }
                dp[i][j+add] %= mod;
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) res = (res + dp[0][i]) % mod;
//    if(!nz) res++;
    cout << res % mod << endl;

}