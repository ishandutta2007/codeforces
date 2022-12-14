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

const int N = (int) 1005, mod = (int) 0;
const double eps = 1e-9;
vector<int> adj[N];
int trap[N], is_trap[N], t, tid[N];
double c[N][N], tmp[N], res[N], g[N][N], a[N][N];
bool is_zero(double x) { return fabs(x) < eps; }
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int j = 0; j < n; ++j) {
        cin >> is_trap[j];
        if (is_trap[j]) {
            tid[j] = t;
            trap[t++] = j;
        } else {
            tid[j] = -1;
        }
    }
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << setprecision(5) << fixed;
    m = 2 * n;
    for (int v = 0; v < n; ++v) {
        for (int j = 0; j < m; ++j)
            g[v][j] = 0;
        g[v][v] = g[v][n + v] = 1;
        if (!is_trap[v]) {
            for (int u : adj[v])
                g[v][u] -= (double) 1 / adj[v].size();
        }
    }
    for (int k = 0; k < n; ++k) {
        int maxrow = k;
        for (int j = k + 1; j < n; ++j)
            if (g[k][j] >= g[k][maxrow])
                maxrow = j;
        for (int j = 0; j < m; ++j)
            swap(g[maxrow][j], g[k][j]);
        double gkk = g[k][k];
        for (int j = 0; j < m; ++j)
            g[k][j] /= gkk;
        for (int j = 0; j < n; ++j)
            if (j != k) {
                double z = g[j][k];
                for (int i = k; i < m; ++i)
                    g[j][i] -= g[k][i] * z;
            }
    }
    for (int j = 0; j < n; ++j) {
        if (is_trap[j]) {
            res[tid[j]] = g[0][j + n];
        }
    }
    for (int j = 0; j < t; ++j)
        for (int i = 0; i < t; ++i) {
            for (int u : adj[trap[j]])
                a[j][i] += g[u][n + trap[i]];
            a[j][i] /= adj[trap[j]].size();
        }
    k -= 2;
    for (int j = 0; j < 30; ++j) {
        if (k >> j & 1) {
            for (int i = 0; i < t; ++i) {
                tmp[i] = res[i];
                res[i] = 0;
            }
            for (int i = 0; i < t; ++i) {
                for (int j = 0; j < t; ++j) {
                    res[i] += tmp[j] * a[j][i];
                }
            }
        }
        for (int x = 0; x < t; ++x)
            for (int y = 0; y < t; ++y) {
                c[x][y] = 0;
                for (int z = 0; z < t; ++z)
                    c[x][y] += a[x][z] * a[z][y];
            }
        for (int x = 0; x < t; ++x)
            for (int y = 0; y < t; ++y)
                a[x][y] = c[x][y];
    }
    cout << res[tid[n - 1]] << endl;


}