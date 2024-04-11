#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <utility>
#include <tuple>

using namespace std;

typedef long long ll;

const int MAXN = 300500;
const ll INF = 1000000000000000ll;

int n;
int a[MAXN];

vector< int > g[MAXN];
ll dp[2][2][MAXN];

ll res;

void
dfs(int x)
{
    dp[0][0][x] = 0ll;
    dp[1][0][x] = -INF;
    dp[0][1][x] = -INF;
    dp[1][1][x] = a[x];
    for (auto son : g[x]) {
        dfs(son);
        ll add0 = dp[0][0][son];
        ll add1 = max(dp[1][0][son], dp[1][1][son]);
        ll n00 = max(dp[0][0][x] + add0, dp[1][0][x] + add1);
        ll n01 = max(dp[0][1][x] + add0, dp[1][1][x] + add1);
        ll n10 = max(dp[1][0][x] + add0, dp[0][0][x] + add1);
        ll n11 = max(dp[1][1][x] + add0, dp[0][1][x] + add1);
        dp[0][0][x] = max(dp[0][0][x], n00);
        dp[0][1][x] = max(dp[0][1][x], n01);
        dp[1][0][x] = max(dp[1][0][x], n10);
        dp[1][1][x] = max(dp[1][1][x], n11);
    }
    res = max(res, max(dp[1][1][x], dp[0][0][x]));
    res = max(res, dp[1][0][x]);
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int par;
        cin >> par >> a[i];
        --par;
        if (par != -1) {
            g[par].push_back(i);
        }
    }
    res = 0ll;
    dfs(0);
    cout << res << '\n';
    return 0;
}