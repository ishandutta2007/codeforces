//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "queue"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
vector<pair<int, int>> mve = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//LRDU
string ldru = "LRDU";
vector<vector<pair<int, int>>> g;
vector<int> prc;
priority_queue<pair<int, int>> que;
void addedge(int a, int b, int c) {
    //cerr << a / 3 << ' ' << a % 3 << ' ' << b / 3 << ' ' << b % 3 << '\n';
    //g[a].push_back({b, c});
    g[b].push_back({a, c});
}
void solve() {
    int n, m;
    cin >> n >> m;
    int p, q;
    cin >> p >> q;
    g.assign(n * m, {});
    prc.assign(n * m, -1);
    vector<vector<int>> ex(n, vector<int>(m));
    vector<vector<int>> crd(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '.')
                ex[i][j] = 1;
            if (c == '#')
                ex[i][j] = -1;
            int ind = -1;
            for (int k = 0; k < 4; ++k) {
                if (ldru[k] == c)
                    ind = k;
            }
            crd[i][j] = ind;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (crd[i][j] != -1) {
                int dx = mve[crd[i][j]].first, dy = mve[crd[i][j]].second;
                int i2 = i + dx, j2 = j + dy;
                //
                // cerr << "!" << i << ' ' << j << ' ' << i2 << ' ' << j2 << '\n';
                int i3 = i2 + dx, j3 = j2 + dy;
                if (0 <= i3 and i3 < n and 0 <= j3 and j3 < m and ex[i3][j3] != -1) {
                    addedge(i * m + j, i3 * m + j3, q);
                }
                vector<pair<int, int>> tcrd;
                if (dx == 0) {
                    tcrd = {{i2 + 1, j2},
                            {i2 - 1, j2}};
                } else {
                    tcrd = {{i2, j2 + 1},
                            {i2, j2 - 1}};
                }
                for (auto[i3, j3] : tcrd) {
                   // cerr << i << ' ' << j << ' ' << i3 << ' ' << j3 << '\n';
                    if (0 <= i3 and i3 < n and 0 <= j3 and j3 < m and ex[i3][j3] != -1) {
                        addedge(i * m + j, i3 * m + j3, p);
                    //   cerr << "II" << i3 << ' ' << j3 << '\n';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ex[i][j] == 1)
                que.push({0, i * m + j});
        }
    }
    while (!que.empty()) {
        auto [val, ind] = que.top();
        if (ex[ind/m][ind%m] == -1)
            exit(1);
        que.pop();
        val = -val;
        if (prc[ind] != -1)
            continue;
        //cerr << val << '\n';
        prc[ind] = val;
        for (auto [u, c] : g[ind])
            que.push({-(val+c), u});
    }
    int res = 1e18;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n) {
                if (prc[i * m + j] != -1 and prc[(i + 1) * m + j] != -1)
                    res = min(res, prc[i * m + j] + prc[(i + 1) * m + j]);
            }
            if (j + 1 < m) {
                if (prc[i * m + j] != -1 and prc[(i) * m + j + 1] != -1)
                    res = min(res, prc[i * m + j] + prc[(i) * m + j + 1]);
            }
        }
    }
    if (res > 1e17)
        cout << "-1\n";
    else
        cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}