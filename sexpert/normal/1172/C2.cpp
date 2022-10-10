#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAXM = 3005;
int n, m, goods, bads;

ll inverse(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll inv[300005], wt[300005], gdp[MAXM][MAXM], bdp[MAXM][MAXM];
int type[200005];

inline void add(ll &a, ll b) {
    a = (a + b) % MOD;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> type[i];
    for(int i = 1; i <= n; i++) {
        cin >> wt[i];
        if(type[i])
            goods += wt[i];
        else
            bads += wt[i];
    }
    for(int i = -5000; i <= 5000; i++)
        inv[100*100 + i] = inverse(goods + bads + i);
    for(int i = m; i >= 0; i--) {
        for(int j = min(bads, m - i); j >= 0; j--) {
            if(i + j == m) {
                gdp[i][j] = 1;
                bdp[i][j] = 1;
                continue;
            }
            add(bdp[i][j], (goods + i) * bdp[i + 1][j]);
            if(bads - j > 0)
                add(bdp[i][j], (bads - j - 1) * bdp[i][j + 1]);
            add(gdp[i][j], gdp[i + 1][j] * 2);
            add(gdp[i][j], (goods + i - 1) * gdp[i + 1][j]);
            add(gdp[i][j], (bads - j) * gdp[i][j + 1]);
            gdp[i][j] = (gdp[i][j] * inv[100*100 + i - j]) % MOD;
            bdp[i][j] = (bdp[i][j] * inv[100*100 + i - j]) % MOD;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(type[i])
            cout << (wt[i] * gdp[0][0]) % MOD << '\n';
        else
            cout << (wt[i] * bdp[0][0]) % MOD << '\n';
    }
}