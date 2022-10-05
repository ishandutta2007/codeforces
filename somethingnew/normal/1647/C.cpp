#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pole(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '1')
                pole[i][j] = 1;
        }
    }
    if (pole[0][0] == 1) {
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pole[i][j])
                res.push_back({i, j});
        }
    }
    reverse(all(res));
    cout << res.size() << '\n';
    for (auto[x, y] : res) {
        if (x != 0) {
            cout << x << ' ' << y + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
        } else {
            cout << x + 1 << ' ' << y << ' ' << x + 1 << ' ' << y + 1 << '\n';
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}