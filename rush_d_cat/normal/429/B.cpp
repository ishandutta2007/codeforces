
//      ((`'-"` `""-'`))
//       )-- (
//      / (o _ o) \
//      \( 0 )/
//      _'-.._'='_..-'_
//      /`;#'#'#.-.#'#'#;`\
//      \_))'#'((_/
//      #..#
//      '#. A C!.#'
//      /'#..#'\
//      _\\'#..#'//_
//      (((___)'#'(___)))
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define MOD 1e9 + 7
#define MAXN 1000+10
#define MAXM 500000+10
ll a[MAXN][MAXN], dp1[MAXN][MAXN], dp2[MAXN][MAXN], dp3[MAXN][MAXN], dp4[MAXN][MAXN];
ll max(ll a, ll b) {return a>b?a:b;}
int main()
{
    int m, n, i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            scanf("%I64d", &a[i][j]);
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + a[i][j];
            dp2[n+1-i][j] = max(dp2[n+1-i][j-1], dp2[n+2-i][j]) + a[n+1-i][j];
            dp3[i][m+1-j] = max(dp3[i-1][m+1-j], dp3[i][m+2-j]) + a[i][m+1-j];
            dp4[n+1-i][m+1-j] = max(dp4[n-i+2][m+1-j], dp4[n-i+1][m-j+2]) + a[n+1-i][m+1-j];
        }
    }
    ll res = 0;
    for(i = 2; i < n; i++)
    {
        for(j = 2; j < m; j++)
        {
            res = max(res, dp1[i][j-1] + dp2[i+1][j] + dp3[i-1][j] + dp4[i][j+1]);
            res = max(res, dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1]);
        }
    }
    cout << res << endl;
}