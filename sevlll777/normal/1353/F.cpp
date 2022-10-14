#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

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
        int ans = 1e18;
        vector<int> D;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                D.pb(A[i][j] - i - j);
            }
        }
        for (auto delta : D) {
            if (A[0][0] >= delta) {
                vector<vector<int>> dp(n, vector<int>(m, 1e17));
                dp[0][0] = 0;
                for (int i = 1; i < n; i++) {
                    int g = delta + i;
                    if (A[i][0] >= g) {
                        dp[i][0] = min(dp[i][0], dp[i - 1][0] + A[i][0] - g);
                    }
                }
                for (int j = 1; j < m; j++) {
                    int g = delta + j;
                    if (A[0][j] >= g) {
                        dp[0][j] = min(dp[0][j], dp[0][j - 1] + A[0][j] - g);
                    }
                }
                for (int i = 1; i < n; i++) {
                    for (int j = 1; j < m; j++) {
                        int g = delta + i + j;
                        if (A[i][j] >= g) {
                            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j] - g;
                        }
                    }
                }
                ans = min(ans, dp[n - 1][m - 1] + A[0][0] - delta);
            }
        }
        cout << ans << '\n';
    }


}