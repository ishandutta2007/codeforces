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

const int N = (int) 80, M = 20, mod = (int) 1e9 + 7;
int dp[N][1 << M];
void sadd(int &x, int y) {
    x += y;
    while (x >= mod)
        x -= mod;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, res = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int j = 0; j <= n; ++j) {
        dp[j][0] = 1;
        for (int last = j - 1; last >= 0; --last) {
            int val = 0;
            for (int x = last; val <= M && x < j; ++x)
                val <<= 1, val += s[x] - '0';
            if (val > M)
                break;
            if (val <= 0)
                continue;
            val--;
            if (val >= M) continue; 
            for (int lmask = 0; lmask < (1 << M); ++lmask)
                sadd(dp[j][lmask | (1 << val)], dp[last][lmask]);
        }
        int cur = 0;
        for (int i = 0; i < M; ++i) {
            cur += 1 << i;
            res = (res + dp[j][cur]) % mod;
        }
    }
    cout << res << '\n';
}