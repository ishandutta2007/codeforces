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

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define double long double
const int N = 21, mod = 0;
double res[N], dp[1 << N], p[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] != 0)
            m++;
    }
    k = min(k, m);
    dp[0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
        double s = 0;
        int flag = 0;
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) {
                if (p[i] == 0) flag = 1;
                s += p[i];
            }
        if (flag) continue;
        for (int last = 0; last < n; ++last)
            if (mask >> last & 1) {
                dp[mask] += dp[mask ^ (1 << last)] * (p[last] / (1 - s + p[last]));
            }
    }
    for (int mask = 0; mask < (1 << n); ++mask) if (__builtin_popcount(mask) == k) {
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1)
                res[i] += dp[mask];
    }
    for (int i = 0; i < n; ++i)
        cout << setprecision(50) << fixed << res[i] << ' ';




}