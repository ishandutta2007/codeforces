#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10;
int n, m, ww = 2, fail, M[N];
vector < int > R[2], P[2];
vector < pair < int , int > > Adj[N];
void DFS(int v, int h, int w)
{
    M[v] = h;
    P[h].pb(v);
    for (auto X : Adj[v])
    {
        if (M[X.x] == -1)
        {
            DFS(X.x, h ^ X.y ^ w, w);
            continue;
        }
        if (M[X.x] != (h ^ X.y ^ w))
            fail = 1;
    }
}
void Solve(int w)
{
    for (int i = 1; i <= n; i++)
        M[i] = -1;
    fail = 0;
    for (int i = 1; i <= n; i++)
        if (M[i] == -1)
        {
            P[0].clear();
            P[1].clear();
            DFS(i, 1, w);
            if (fail)
            {
                ww --;
                for (int j = 0; j < N; j++)
                    R[w].pb(j);
                return ;
            }
            if (P[0].size() < P[1].size())
                for (auto X : P[0])
                    R[w].pb(X);
            else
                for (auto X : P[1])
                    R[w].pb(X);
        }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, v, u; i < m; i++)
    {
        scanf("%d%d", &v, &u);
        char ch = getchar(); ch = getchar();
        Adj[v].pb({u, (ch == 'R')});
        Adj[u].pb({v, (ch == 'R')});
    }
    Solve(0);
    Solve(1);
    if (!ww)
        return puts("-1");
    if (R[0].size() < R[1].size())
    {
        printf("%d\n", (int)R[0].size());
        for (auto X : R[0])
            printf("%d ", X);
        return (0);
    }
    printf("%d\n", R[1].size());
    for (auto X : R[1])
        printf("%d ", X);
    return (0);

}