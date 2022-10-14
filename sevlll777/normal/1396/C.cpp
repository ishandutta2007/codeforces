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
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<int> A(1 + n);
    for (int i = 1; i <= n; i++) cin >> A[i];
    vector<int> C1(n + 1), C2(n + 1);
    for (int i = 1; i <= n; i++) {
        C1[i] = r1 * A[i] + r3;
        C2[i] = min((A[i] + 1) * r1, r2) + r1;
    }
    vector<int> dp(n + 2);
    dp[n + 1] = -d;
    dp[n] = min(C1[n], C2[n] + 2 * d);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1] + 2 * d + min(C1[i], C2[i]);
    }
    vector<int> dp2(n + 2);
    dp2[0] = -d;
    dp2[1] = C1[1];
    for (int i = 2; i <= n; i++) {
        int A1 = dp2[i - 1] + d + min(C1[i], 2 * d + C2[i]);
        int A2 = dp2[i - 2] + 4 * d + min(C1[i - 1], C2[i - 1]) + min(C1[i], C2[i]);
        dp2[i] = min(A1, A2);
    }
    int ans = dp[1];
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dp2[i] + dp[i + 1] + d);
    }
    cout << ans << '\n';

}