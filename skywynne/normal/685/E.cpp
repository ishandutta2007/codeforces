#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 4, N = 1003;
int n, m, q, F[M], T[M], dp[N][N];
bitset < M > Can;
vector < pair < pair < int , int > , pair < int , int > > > Q[M];
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &F[i], &T[i]);
    for (int i = 0, l, r, s, t; i < q; i++)
        scanf("%d%d%d%d", &l, &r, &s, &t), Q[l].push_back({{i, r}, {s, t}});
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = 1e9;
    for (int i = m; i; i--)
    {
        int f = F[i], t = T[i];
        dp[f][t] = dp[t][f] = i;
        for (int j = 1; j <= n; j++)
            dp[t][j] = min(dp[t][j], dp[f][j]);
        for (int j = 1; j <= n; j++)
            dp[f][j] = min(dp[f][j], dp[t][j]);
        for (auto &X : Q[i])
            Can[X.first.first] = (dp[X.second.first][X.second.second] <= X.first.second);
    }
    for (int i = 0; i < q; i++)
    {
        if (Can[i])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return (0);
}