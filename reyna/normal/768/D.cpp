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
const double eps = 1e-7;
const int N = (int) 1e5 + 5, mod = (int) 0;
double odp[N], dp[N];
int res[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, cnt = 0, q, pt = 1;
    cin >> k >> q;
    dp[0] = 1;
    while (pt <= 1001) {
        cnt++;
        for (int j = 0; j <= k; ++j) odp[j] = dp[j], dp[j] = 0;
        for (int j = 0; j <= k; ++j) {
            dp[j] += odp[j] * (double) j / k;
            dp[j + 1] += odp[j] * (double) (k - j) / k;
        }
        while (pt <= 1001 && dp[k] > ((double) pt - eps) / 2000) {
            res[pt] = cnt;
            pt++;
        }
    }
    while (q--) {
        int x;
        cin >> x;
        cout << res[x] << '\n';
    }
}