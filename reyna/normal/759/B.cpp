// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
#define int long long
const int N = (int) 1e5 + 5, mod = (int) 0;
int dp[N], a[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    for (int j = 1; j <= n; ++j) {
        cin >> a[j];
        int z = lower_bound(a + 1, a + j + 1, a[j] - 90 + 1) - a - 1;
        dp[j] = dp[z] + 50;
        dp[j] = min(dp[j], dp[j - 1] + 20);
        z = lower_bound(a + 1, a + j + 1, a[j] - 1440 + 1) - a - 1;
        dp[j] = min(dp[j], dp[z] + 120);
        cout << dp[j] - dp[j - 1] << '\n';
    }
}