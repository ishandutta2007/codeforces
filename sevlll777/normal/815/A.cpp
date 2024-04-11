#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }
    string ROW = "row", COL = "col";
    if (n > m) {
        vector<vector<int>> G2(m, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                G2[j][i] = G[i][j];
            }
        }
        G = G2;
        swap(n, m);
        swap(ROW, COL);
    }
    vector<pair<string, int>> ans;
    for (int i = 0; i < n; i++) {
        int m0 = 1e9;
        for (auto x : G[i]) m0 = min(m0, x);
        for (int j = 0; j < m; j++) G[i][j] -= m0;
        for (int _ = 0; _ < m0; _++) ans.pb({ROW, i+1});
    }
    for (int j = 0; j < m; j++) {
        int kek = G[0][j];
        for (int i = 1; i < n; i++) {
            if (G[i][j] != kek) {
                cout << -1;
                return 0;
            }
        }
        for (int _ = 0; _ < kek; _++) ans.pb({COL, j+1});
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

}