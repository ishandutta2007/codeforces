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
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = 0; j <= (m - 1) / 2; j++) {
                set<int> s1 = {i, n - 1 - i};
                set<int> s2 = {j, m - 1 - j};
                vector<int> heh;
                for (auto p : s1) {
                    for (auto k : s2) {
                        heh.pb(A[p][k]);
                    }
                }
                sort(heh.begin(), heh.end());
                int med = (heh[heh.size() / 2] + heh[(heh.size() - 1) / 2]) / 2;
                for (auto x : heh) {
                    ans += abs(x - med);
                }
            }
        }
        cout << ans;
        cout << '\n';
    }
}