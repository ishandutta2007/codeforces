#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 18;
int a[N * 2], dp[N * 2][2], pw, ans = 1, x;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0;
        return 0;
    }
    pw = 1 << n;
    rep(i, k) {
        cin >> x;
        a[pw + x - 1] = 1;
    }
    rep(i, pw / 2)
        if (a[pw + i * 2] || a[pw + i * 2 + 1])
            ans++;
    for (int i = pw - 1; i > 0; i--) {
        a[i] = a[i * 2] + a[i * 2 + 1];
        if (!a[i])
            continue;
        int i1 = i * 2, i2 = i1 + 1;
        if (i >= pw / 2)
            continue;
        dp[i][0] = 1 + dp[i1][0] + dp[i2][0];
        if (i >= pw / 4) {
            if (a[i] >= 2)
                dp[i][1] = 3;
            continue;
        }
        if (dp[i1][0] && dp[i2][0])
            dp[i][1] = max(dp[i][1], 3 + dp[i1][0] + dp[i2][0] + max(dp[i1][0], dp[i2][0]));
        if (dp[i1][1])
             dp[i][1] = max(dp[i][1], 3 + dp[i1][1] + max(dp[i2][0] * 2, dp[i2][1]));
        if (dp[i2][1])
            dp[i][1] = max(dp[i][1], 3 + dp[i2][1] + max(dp[i1][0] * 2, dp[i1][1]));
        //cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << max(dp[1][0] * 2, dp[1][1]) + ans;
}