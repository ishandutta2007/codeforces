#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
using namespace std;
#define all(x) x.begin(), x.end()
int eq(vector<vector<int>> &p, int x, int y) {
    int t = -1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (p[x+i][y+j] != -1) {
                if (t == -1)
                    t = p[x + i][y + j];
                if (t != p[x + i][y + j])
                    return -1;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            p[x+i][y+j] = -1;
        }
    }
    return t;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pole(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pole[i][j];
        }
    }
    vector<array<int, 3>> ans;
    vector<pair<int, int>> gd;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int cl = eq(pole, i, j);
            if (cl != -1) {
                ans.push_back({i+1,j+1,cl});
                gd.push_back({i, j});
            }
        }
    }
    while (!gd.empty()) {
        auto [x, y] = gd.back();
        gd.pop_back();
        for (int i = max(x-1, 0); i < min(x + 2, n - 1); ++i) {
            for (int j = max(y-1, 0); j < min(y + 2, m - 1); ++j) {
                int cl = eq(pole, i, j);
                if (cl != -1) {
                    ans.push_back({i+1,j+1,cl});
                    gd.push_back({i, j});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pole[i][j] != -1) {
                cout << "-1\n";
                return;
            }
        }
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto [x, y, c] : ans)
        cout << x << ' ' << y << ' ' << c << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1;
    while (n--) solve();
}