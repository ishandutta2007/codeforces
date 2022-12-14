// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 2e5 + 5, mod = (int) 1e9 + 7;

vector<int> c;
int af[2], s[N], t[N], sz[N], dp[2][2], ndp[2][2], mark[N], all[2], nall[2];
vector<int> contain[N], adj[N];
int satisfy(int clause, int i, int j, int v0, int v1) {
    if (mark[i] && mark[j]) {
        ++i, ++j;
        if (i == abs(t[clause])) swap(i, j), swap(v0, v1);
        int a = (s[clause] < 0? (v0 ^ 1): v0);
        int b = (t[clause] < 0? (v1 ^ 1): v1);
   //     cout << " IN " << a << ' ' << b << ' ' << i << ' ' << j << endl;
        return a | b;
    }
    return 0;
}

void dfs(int v, int st, int init, int p = -1) {
    mark[v] = 1;
    c.push_back(v);
    memset(ndp, 0, sizeof ndp);
    for (int give = 0; give < 2; ++give) if ((v != st) || (give == init)) {
        for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) {
            int z = 0;
            for (int j : contain[v]) {
                int u = abs(s[j]) + abs(t[j]) - v - 2;
                if (!mark[u]) continue;
//                cout << " What " << u << ' ' << v << endl;
                z ^= satisfy(j, u, v, (u == v? give: ((u == st)? init: b)), give);
            }
            ndp[z ^ a][give] = (ndp[z ^ a][give] + dp[a][b]) % mod;
        }
    }
    memcpy(dp, ndp, sizeof dp);
    for (int x : adj[v]) {
        int u = abs(s[x]) + abs(t[x]) - v - 2;
        if (!mark[u]) {
            dfs(u, st, init, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int mul = 1;
    all[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> sz[i];
        if (sz[i] == 2) {
            int u, v;
            cin >> u >> v;
            if (abs(u) == abs(v)) {
                if (u == v) {
                    all[0] = all[1] = (all[0] + all[1]) % mod;
                    mark[abs(u) - 1] = 1;
                } else {
                    swap(all[0], all[1]);
                    all[0] = all[0] * 2 % mod;
                    all[1] = all[1] * 2 % mod;
                    mark[abs(u) - 1] = 1;
                }
                continue;
            }
            s[i] = u;
            t[i] = v;
            adj[abs(s[i]) - 1].push_back(i);
            adj[abs(t[i]) - 1].push_back(i);
            contain[abs(u) - 1].push_back(i);
            contain[abs(v) - 1].push_back(i);
        } else {
            int x;
            cin >> x;
            s[i] = t[i] = x;
            contain[abs(x) - 1].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) if (!mark[i]) {
        memset(af, 0, sizeof af);
        c.clear();
        for (int j = 0; j < 2; ++j) {
            memset(dp, 0, sizeof dp);
            dp[0][j] = 1;
            if (j == 1) for (auto x : c) mark[x] = 0;
            dfs(i, i, j);
            af[0] = (af[0] + dp[0][0]) % mod;
            af[0] = (af[0] + dp[0][1]) % mod;
            af[1] = (af[1] + dp[1][0]) % mod;
            af[1] = (af[1] + dp[1][1]) % mod;
        }

        nall[0] = all[0];
        nall[1] = all[1];
        all[0] = all[1] = 0;
        for (int a = 0; a < 2; ++a)
            for (int x = 0; x < 2; ++x)
                all[a ^ x] = (all[a ^ x] + nall[x] * 1ll * af[a]) % mod;
    }
    cout << all[1] << '\n';


}