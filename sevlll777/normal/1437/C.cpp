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
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        int dp[n][2 * n + 3];
        for (int i = 0; i < n; i++) {
            for (int x = 1; x < 2 * n + 3; x++) {
                dp[i][x] = abs(x - A[i]);
                if (i != 0) {
                    int m = 1e9;
                    for (int y = 1; y < x; y++) m = min(m, dp[i - 1][y]);
                    dp[i][x] += m;
                }
            }
        }
        int a = 1e9;
        for (int x = 1; x < 2 * n + 3; x++) a = min(a, dp[n - 1][x]);
        cout << a << '\n';
    }
}