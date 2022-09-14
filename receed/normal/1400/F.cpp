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

const int N = 1001, M = 1 << 21;
int num[M], li[M], dp[N][30000], bd[M];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int x, cc = 0;
    cin >> s >> x;
    int n = s.size(), ans = n;
    if (x == 1) {
        ans = 0;
        for (char c : s)
            if (c == '1')
                ans++;
        cout << ans;
        return 0;
    }
    vector<int> di;
    for (int i = 2; i < x; i++)
        if (x % i == 0)
            di.push_back(i);
    rep(i, 1 << (x + 1)) {
        int f = 0;
        rep(j, x)
            if (((i >> j) & 3) == 3)
                f = 1;
        if (!f) {
            li[cc] = i;
            num[i] = cc++;
            if ((i & 1) && ((i >> x) & 1)) {
                int fl = 0;
                rep(j, x + 1)
                    if ((i >> j) & 1) {
                        for (int k : di)
                            if (k <= j && ((i >> (j - k)) & 1))
                                fl = 1;
                    }
                if (!fl) {
                    bd[i] = 1;
                }
            }
        }
        else
            num[i] = -1;
    }
    rep(i, cc)
        dp[0][i] = n;
    dp[0][num[1]] = 0;
    rep(i, n) {
        int d = s[i] - '0';
        rep(j, cc)
            dp[i + 1][j] = dp[i][j] + 1;
        if (d == 1) {
            rep(j, cc)
                dp[i + 1][num[1]] = min(dp[i + 1][num[1]], dp[i][j]);
            continue;
        }
        rep(j, cc) {
            if (dp[i][j] >= n)
                continue;
            int nm = ((li[j] << d) | 1) & ((1 << (x + 1)) - 1);
            if (bd[nm])
                continue;
            nm = num[nm & ((1 << x) - 1)];
            dp[i + 1][nm] = min(dp[i + 1][nm], dp[i][j]);
        }
    }
    rep(i, cc)
        ans = min(ans, dp[n][i]);
    cout << ans;
}