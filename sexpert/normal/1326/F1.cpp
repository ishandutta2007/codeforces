#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int adj[14][14];
ll dp[1 << 14][1 << 6][14], dp2[1 << 14][1 << 6][14];
ll res[1 << 14];
ll lol[14][1 << 6], kek[14][1 << 6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            adj[i][j] = (s[j] - '0');
    }
    int k = n/2, k1 = n - k;
    for(int i = 0; i < n; i++)
        dp[1 << i][0][i] = dp2[1 << i][0][i] = 1;
    for(int vms = 1; vms < (1 << n); vms++) {
        int pc = __builtin_popcount(vms);
        if(pc == 1 || pc > k1)
            continue;
        for(int pms = 0; pms < (1 << (k1 - 1)); pms++) {
            for(int v = 0; v < n; v++) {
                if((1 << v) & vms) {
                    for(int u = 0; u < n; u++) {
                        if(u == v)
                            continue;
                        if(((1 << u) & vms) == 0)
                            continue;
                        if(adj[u][v] == (pms & 1)) 
                            dp[vms][pms][v] += dp[vms ^ (1 << v)][pms / 2][u];
                        if(adj[u][v] == (pms >> (pc - 2)))
                            dp2[vms][pms][v] += dp2[vms ^ (1 << v)][pms & ((1 << (pc - 2)) - 1)][u];
                    }
                }
            }
        }
    }
    for(int m1 = 0; m1 < (1 << n); m1++) {
        int pc = __builtin_popcount(m1);
        if(pc != k)
            continue;
        int m2 = (1 << n) - 1 - m1;
        for(int u = 0; u < n; u++) {
            if((1 << u) & m2)
                continue;
            for(int v = 0; v < n; v++) {
                if((1 << v) & m1)
                    continue;
                for(int p1 = 0; p1 < (1 << (k - 1)); p1++) {
                    for(int p2 = 0; p2 < (1 << (k1 - 1)); p2++) {
                        res[(p1 << k1) + (adj[u][v] << (k1 - 1)) + p2] += dp[m1][p1][u] * dp2[m2][p2][v];
                    }
                }
            }
        }
    }
    for(int i = 0; i < (1 << (n - 1)); i++)
        cout << res[i] << ' ';
    cout << '\n';
}