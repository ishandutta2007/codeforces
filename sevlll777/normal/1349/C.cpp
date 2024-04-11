// #pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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

using namespace std;
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> F(n);
    for (int i = 0; i < n; i++) cin >> F[i];
    vector<vector<int>> G(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1 && F[i - 1][j] == F[i][j]) {
                G[i][j] = 0;
            }
            if (i < n - 1 && F[i + 1][j] == F[i][j]) {
                G[i][j] = 0;
            }
            if (j >= 1 && F[i][j - 1] == F[i][j]) {
                G[i][j] = 0;
            }
            if (j < m - 1 && F[i][j + 1] == F[i][j]) {
                G[i][j] = 0;
            }
        }
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == 0) {
                q.pb({i, j});
            }
        }
    }
    vector<pair<int, int>> Ffff = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        pair<int, int> jjj = q.front();
        int i = jjj.first, j = jjj.second;
        q.pop_front();
        for (auto D : Ffff) {
            int di = D.first, dj = D.second;
            int i2 = i + di, j2 = j + dj;
            if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m && G[i2][j2] == 1e9) {
                G[i2][j2] = G[i][j] + 1;
                q.pb({i2, j2});
            }
        }
    }
    // cout << G[0][0] << '\n';
    while (t--) {
        int a, b;
        long long p;
        cin >> a >> b >> p;
        a--;
        b--;
        if (G[a][b] > p || G[a][b] == 1e9) {
            cout << F[a][b] << '\n';
        } else {
            p -= G[a][b];
            if (p % 2 == 0) {
                cout << F[a][b] << '\n';
            } else {
                if (F[a][b] == '0') {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }

        }
    }


}