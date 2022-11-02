#include<bits/stdc++.h>
#define f first
#define s second.f
#define t second.second
using namespace std;
long long n, m, r, p, Mx, dp[100010], C[100010];
vector < int > V[100010];
int main()
{
    scanf("%I64d %I64d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%I64d %I64d", &r, &p);
        C[r] ++;
        C[p] ++;
        V[max(r, p)].push_back(min(r, p));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < V[i].size(); j++)
        {
            dp[i] = max(dp[i], dp[V[i][j]] + 1);
        }
        Mx = max(Mx, (dp[i] + 1) * C[i]);
    }
    printf("%I64d", Mx);
    return (0);
}