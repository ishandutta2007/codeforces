#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 19;

int n, m;
int E[N][N];
ll dp[N][(1 << N) + 5];
int fir[(1 << N) + 5];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        E[a][b] = E[b][a] = 1;
    }

    for(int i = 0; i < n; i++) dp[i][(1 << i)] = 1;
    for(int mask = 1; mask < (1 << n); mask++) {
        int fst = n-1;
        while(!((mask >> fst) & 1)) fst--;
        fir[mask] = fst;
    }

    for(int mask = 1; mask < (1 << n); mask ++) {
        if((1 << fir[mask]) == mask) continue;
        for(int i = fir[mask] - 1; i >= 0; i--) {
            if(!((mask >> i) & 1)) continue;
            for(int j = 0; j < n; j++) {
                if(!((mask >> j) & 1)) continue;
                if(!E[i][j]) continue;
                dp[i][mask] += dp[j][mask ^ (1 << i)];
            }
        }
    }

    ll res = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        int pcnt = __builtin_popcount(mask);
        if(pcnt < 3) continue;
        int fst = fir[mask];
        for(int i = 0; i < n; i++) {
            if(E[fst][i]) res += dp[i][mask];
        }
    }
    cout << res / 2 << endl;


}