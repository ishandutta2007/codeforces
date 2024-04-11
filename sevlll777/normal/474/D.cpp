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
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, k;
    cin >> t >> k;
    vector<int> dp(1e5 + 11, 1);
    dp[0] = 1;
    for (int i = 1; i <= 1e5 + 5; i++) {
        dp[i] = dp[i - 1];
        if (i >= k) dp[i] += dp[i - k];
        dp[i] %= M;
    }
    for (int i = 1; i <= 1e5 + 5; i++) {
        dp[i] += dp[i - 1];
        dp[i] %= M;
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (M + dp[b] - dp[a - 1]) % M << '\n';
    }
}