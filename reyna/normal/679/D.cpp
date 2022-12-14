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
const int N = 405, mod = 0;

int d[N][N], mat[N][N], deg[N];
double cnt[N][N];
double go[N][N], val[N], cur[N][N], sum[N];;
vector<int> p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j)
                d[i][j] = 1e9;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        deg[u]++; deg[v]++;
        d[u][v] = d[v][u] = mat[u][v] = mat[v][u] = 1;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    double best = 0;
    for (int st = 0; st < n; ++st) {
        double res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                go[i][j] = 0;
            p[i].clear();
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) if (mat[i][j])
                go[i][d[st][j]] += (double) 1 / (deg[j] * 1ll * n);
        for (int i = 0; i < n; ++i) {
            p[d[st][i]].push_back(i);
        }
        for (int dis = 0; dis <= n; ++dis) {
            if (p[dis].size() <= 1) {
                res += (double) p[dis].size() / n;
                continue;
            }
            double mx = 0;
            vector<pair<int, int>> c;
            for (int see = dis - 1; see <= dis + 1; ++see) if (see >= 0) {
                for (int v : p[see])
                    for (int u = 0; u < n; ++u) {
                 //       val[u] -= cur[u][d[u][v]];
           //             cnt[u][d[u][v]] += go[v][dis];
                        sum[u] += go[v][dis];
                        cur[u][d[u][v]] = max(cur[u][d[u][v]], go[v][dis]);
                        c.push_back(make_pair(u, d[u][v]));
               //         val[u] += cur[u][d[u][v]];
                    }

            }
            for (pair<int, int> x : c) {
                int u = x.first;
                if (cur[x.first][x.second] != 0) {
                    val[u] += cur[x.first][x.second] / sum[u];
                //    cout << sum[u] << endl;
                }
                cur[x.first][x.second] = 0;
         //       cnt[x.first][x.second] = 0;
            }
            for (int v = 0; v < n; ++v) {
                mx = max(mx, val[v]);
              //  cout << st << ' ' << v << ' ' << val[v] << endl;
                sum[v] = 0;
                val[v] = 0;
            }
            res += max((double) 1, mx * (double) p[dis].size()) / n;
        }
   //     cout << st << ' ' << res << endl;
        best = max(res, best);
    }
    cout << setprecision(10) << fixed << best << endl;
}