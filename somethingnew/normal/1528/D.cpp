#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long
inline void upd(int & a, int b) {
    if (b == -1)
        return;
    if (a == -1)
        a = b + 1;
    a = min(a, b + 1);
}
vector<vector<int>> g;
vector<int> fndans(int v) {
    vector<int> dst(g.size(), -1);
    dst[v] = 0;
    vector<int> mindst(g.size(), -1);
    mindst = g[v];
    int n = g.size();
    while (1) {
        int p = -1;
        for (int i = 0; i < g.size(); ++i) {
            if (dst[i] == -1 and (p == -1 or mindst[p] > mindst[i])) {
                p = i;
            }
        }
        if (p == -1)
            break;
        //cout << p << ' ' << mindst[p] << endl;
        int t = mindst[p];
        dst[p] = t;
        for (int i = 0; i < g.size(); ++i) {
            mindst[i] = min(mindst[i], t + g[p][((i - t) % n + n) % n]);
        }
    }
    return dst;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }
    for (int i = 0; i < n; ++i) {
        for (int ipl = 1; ipl < 10 * n; ++ipl) {
            upd(g[i][(i + ipl) % n], g[i][(i + ipl - 1) % n]);
        }
    }
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = fndans(i);
    }
    for (auto i : ans) {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}