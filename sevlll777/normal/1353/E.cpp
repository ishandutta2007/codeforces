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
        int n, k;
        cin >> n >> k;
        k--;
        string s;
        cin >> s;
        s = '-' + s;
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i] == '1');
        vector<int> dp(n + 1., 1e18);
        for (int i = 1; i <= k; i++) {
            dp[i] = (s[i] == '0') + pref[i - 1];
        }
        for (int i = k + 1; i <= n; i++) {
            dp[i] = min(pref[i - 1] + (s[i] == '0'), dp[i - k - 1] + pref[i - 1] - pref[i - k - 1] + (s[i] == '0'));
        }
        int ans = pref[n] - 1;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[i] + pref[n] - pref[i]);
        }
        cout << max(0LL, ans) << '\n';
    }


}