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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> A(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    int l = -1, r = 1e10;
    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<int> dp(n+1);
        int mim = n - 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = i-1;
            for (int j = 1; j < i; j++) {
                if (abs(A[i] - A[j]) <= m * (i - j)) {
                    dp[i] = min(dp[i], dp[j] + (i - j - 1));
                }
            }
            mim = min(mim, dp[i] + (n - i));
        }
        if (mim <= k) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l + 1 << '\n';

}