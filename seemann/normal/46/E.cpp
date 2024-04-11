#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); a++)
#define clr(a) memset(a, 0, sizeof(a))
#define ll long long
//define _in_s(a, b) (((a) < h)&&((a) >= 0)&&((b) < w)&&((b) >= 0))
const ll INF = (ll)1000000000 * (ll)1000000000;

ll dp[1501][1501];
ll p[1501][1501];

ll maxp[1501];
ll M[1501][1501];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    FOR(i, n)
        FOR(j, m)
           {scanf("%I64d", &M[i][j]);}

    FOR(i, n)
    {
        ll sum = 0;
        for (int j = 0; j <= m; j++)
        {
            p[i][j] = sum;
            if (j != m) sum += M[i][j];
        }

    }



    clr(maxp);

    for (int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
            if (i % 2 == 0)
            {
                if (j == 1 && (n != 1)) {dp[i][j] = -INF;continue;}
                dp[i][j] = maxp[j - 1] + p[i][j];
            }
            else
            {
                if (j == m) {dp[i][j] = -INF;continue;}
                dp[i][j] = maxp[j + 1] + p[i][j];
            }
        if (i % 2 == 0)
        {
            maxp[m + 1] = -INF;
            ll w = 0;
            for (int j = m;j >= 1; --j)
            {
                maxp[j] = max(maxp[j + 1], dp[i][j]);
            }

        }
        else
        {
            maxp[1] = dp[i][1];
            ll w = 0;
            for (int j = 2;j <= m; j++)
            {
                maxp[j] = max(maxp[j - 1], dp[i][j]);
            }
        }
    }
    ll ans = -INF;
    for (int i = 1; i <=  m; i++)
        ans = max(ans, dp[n - 1][i]);
    cout << ans;

    return 0;
}