#define __GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;
int dp[9][9];
int dp2[9][9];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1);
    vector<int> B;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ANS = 0;
    for (int x = 1; x <= m; x++) {
        if (cnt[x] >= 6) {
            ANS += (cnt[x] - 6) / 3;
            cnt[x] = 6 + cnt[x] % 3;
        }
    }
    for (int c1 = 0; c1 <= 8; c1++) {
        for (int c2 = 0; c2 <=8; c2++) {
            dp[c1][c2] = c1 / 3 + c2 / 3;
        }
    }
    for (int x = 1; x <= m; x++) {
        for (int c1 = 0; c1 <= 8; c1++) {
            for (int c2 = 0; c2 <= 8; c2++) {
                dp2[c1][c2] = 0;
                if (c1 >= 3) dp2[c1][c2] = max(dp2[c1][c2], 1 + dp2[c1 - 3][c2]);
                if (c2 >= 3) dp2[c1][c2] = max(dp2[c1][c2], 1 + dp2[c1][c2 - 3]);
                for (int w = 0; w <= min({cnt[x], c1, c2}); w++)
                    dp2[c1][c2] = max(dp2[c1][c2], w + dp[cnt[x] - w][c1 - w]);
            }
        }
        for (int c1 = 0; c1 <= 8; c1++) for (int c2 = 0; c2 <= 8; c2++) dp[c1][c2] = dp2[c1][c2];
    }
    cout << ANS + dp[0][0];
}