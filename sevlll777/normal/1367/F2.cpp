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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        sort(B.begin(), B.end());
        map<int, int> next;
        for (int i = 0; i < n - 1; i++) {
            if (B[i] != B[i + 1]) {
                next[B[i]] = B[i + 1];
            }
        }
        map<int, vector<int>> indexes;
        for (int i = 0; i < n; i++) {
            indexes[A[i]].pb(i);
        }
        vector<int> dp(n);
        dp[n - 1] = 1;
        int ans = 1;
        for (int j = n - 2; j >= 0; j--) {
            dp[j] = 1;
            if (j != indexes[A[j]].back()) {
                dp[j] = max(dp[j], 1 + dp[(*upper_bound(indexes[A[j]].begin(), indexes[A[j]].end(), j))]);
            }
            if (next.find(A[j]) != next.end()) {
                int kio = (int) indexes[next[A[j]]].size();
                int heh = (int) (upper_bound(indexes[next[A[j]]].begin(), indexes[next[A[j]]].end(), j) - indexes[next[A[j]]].begin());
                dp[j] = max(dp[j], 1 + kio - heh);
                if (indexes[next[A[j]]][0] >= j) {
                    dp[j] = max(dp[j], kio - heh + dp[indexes[next[A[j]]].back()]);
                }
            }
            ans = max(ans, dp[j]);
        }
        cout << n - ans << '\n';
    }
}