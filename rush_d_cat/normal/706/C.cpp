#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <cmath>
#include <string.h>
using namespace std;
#define min(a, b) a < b ? a: b;
typedef __int64 ll;
const int maxn = 100000 + 10;
const ll INF = 1e14 + 10;
string s[maxn], r[maxn];
ll dp[maxn][2], c[maxn];
int main()
{
    int n ,i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(i = 1; i <= n; i++)
    {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    dp[1][0] = 0; dp[1][1] = c[1];
    for(i = 2; i <= n; i++)
    {
        dp[i][0] = INF; dp[i][1] = INF;
        if(s[i] >= s[i - 1]) dp[i][0] = min(dp[i - 1][0], dp[i][0]);
        if(s[i] >= r[i - 1]) dp[i][0] = min(dp[i - 1][1], dp[i][0]);
        if(r[i] >= s[i - 1]) dp[i][1] = min(dp[i - 1][0] + c[i], dp[i][1]);
        if(r[i] >= r[i - 1]) dp[i][1] = min(dp[i - 1][1] + c[i], dp[i][1]);
    }
    ll res = min(dp[n][1], dp[n][0]);
    if(dp[n][0] == INF && dp[n][1] == INF)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}