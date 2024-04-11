#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll dp[505][505];
int col[505];

ll calc(int L, int R) {
    if(dp[L][R] != -1)
        return dp[L][R];
    if(L == R + 1)
        return dp[L][R] = 1;
    int x = 0, mi = 10000;
    for(int i = L; i <= R; i++) {
        if(col[i] < mi) {
            mi = col[i];
            x = i;
        }
    }

    ll waysL = 0, waysR = 0;
    for(int i = L; i <= x; i++)
        waysL = (waysL + calc(L, i - 1) * calc(i, x - 1)) % MOD;
    for(int i = R; i >= x; i--)
        waysR = (waysR + calc(i + 1, R) * calc(x + 1, i)) % MOD;
    dp[L][R] = (waysL * waysR) % MOD;
    return dp[L][R];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> col[i];
    for(int i = 0; i < 505; i++)
        for(int j = 0; j < 505; j++)
            dp[i][j] = -1;
    cout << calc(1, n) << '\n';
}