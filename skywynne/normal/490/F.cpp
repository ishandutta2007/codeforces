#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 6006;
int n, Mx, A[N], dp[N];
vector < int > Adj[N];
void DFS(int v, int p = 0)
{
    int lb = lower_bound(dp, dp + N, A[v]) - dp, lst = dp[lb];
    dp[lb] = A[v]; Mx = max(Mx, lb);
    for (int &u : Adj[v])
        if (u != p)
            DFS(u, v);
    dp[lb] = lst;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    memset(dp, 1, sizeof(dp));
    for (int i = 1; i <= n; i++)
        DFS(i);
    return !printf("%d", Mx + 1);
}