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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, n;
    cin >> r >> n;
    vector<int> T(1 + n), X(1 + n), Y(1 + n);
    X[0] = 1;
    Y[0] = 1;
    for (int i = 1; i <= n; i++) cin >> T[i] >> X[i] >> Y[i];
    vector<int> dp(n + 1);
    int mem = -1e9;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = mem + 1;
        for (int j = i - 1; j >= max(0, i - 1010); j--) {
            if (abs(T[i] - T[j]) >= abs(X[i] - X[j]) + abs(Y[i] - Y[j])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (i >= 1007) {
            mem = max(mem, dp[i - 1007]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}