#include <iostream>
#include <vector>

using namespace std;
#define N 1002
int w[N], b[N], par[N];
int n, m, weigh;
int dp[N][N];
vector<int> vec[N];

int find(int x)
{
    return par[x] == 0 ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    int cx = find(x);
    int cy = find(y);
    if (cx != cy)
    {
        par[cx] = cy;
    }
}

int main() 
{
    scanf("%d %d %d", &n, &m, &weigh);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        unite(u, v);
    }

    for (int i = 1; i <= n; i ++)
    {
        vec[find(i)].push_back(i);
    }                          

    dp[0][0] = 0;
    for (int i = 1; i <= weigh; i ++)
    {
        dp[0][i] = -10000000;
    }

    for (int i = 1; i <= n; i ++)
    {
        int ok = vec[i].size();
        int sum_w = 0, sum_b = 0;
        for (int j = 0; j < vec[i].size(); j ++)
        {
            sum_w += w[ vec[i][j] ];
            sum_b += b[ vec[i][j] ];

            for (int k = 0; k <= weigh; k ++)
            {
                if (k >= w[ vec[i][j] ])
                dp[i][k] = max(dp[i - 1][ k - w[ vec[i][j] ] ] + b[ vec[i][j] ], dp[i][k]);
            }
        }
        //printf("sum_W = %d sum_b = %d\n", sum_w, sum_b);

        for (int j = 0; j <= weigh; j ++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if (! ok) 
            {
                continue;
            }
            if (j >= sum_w)
            {
                dp[i][j] = max( dp[i-1][j-sum_w] + sum_b, dp[i][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= weigh; i ++)
    {
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);

}