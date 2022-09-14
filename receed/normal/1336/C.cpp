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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 3002, MOD = 998244353;
ll dp[N][N];
char s[N], t[N];

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    rep(i, n)
        if (i >= m || s[0] == t[i])
            dp[i][i] = 2;
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++) {
            char c = s[j - i + 1];
            if (j + 1 < n && (j + 1 >= m || t[j + 1] == c))
                add(dp[i][j + 1], dp[i][j]);
            if (i > 0 && (i - 1 >= m || t[i - 1] == c))
                add(dp[i - 1][j], dp[i][j]);
        }
    ll ans = 0;
    for (int i = m - 1; i < n; i++)
        add(ans, dp[0][i]);
    cout << ans;
}