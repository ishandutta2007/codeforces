#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 3000 + 10, Mod = 1e9 + 7;
int n, m, q, r, l, t, a, b, c, d, st[N << 3], D[N][N];
vector < int > Adj[N];
vector < int > A[N], B[N];
void BFS(int v)
{
    for (int i = 1; i <= n; i++)
        D[v][i] = 1e9;
    D[v][v] = 0;
    l = r = 0;
    st[r ++] = v;
    while (r - l)
    {
        int u = st[l ++];
        for (auto X  : Adj[u])
            if (D[v][X] > D[v][u] + 1)
                D[v][X] = D[v][u] + 1, st[r ++] = X;
    }
    set < pair < int , int > > S;
    for (int i = 1; i <= n; i++)
        if (i != v && D[v][i] != 1e9)
            S.insert({-D[v][i], i});
    for (auto X : S)
        A[v].pb(X.second);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &r, &t), Adj[r].pb(t);
    for (int i = 1; i <= n; i++)
        BFS(i);
    for (int i = 1; i <= n; i++)
    {
        set < pair < int , int > > S;
        for (int j = 1; j <= n; j++)
            if (i != j && D[j][i] != 1e9)
                S.insert({-D[j][i], j});
        for (auto X : S)
            B[i].pb(X.second);
    }
    int tot = 0;
    vector < int > R; R.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && D[i][j] != 1e9)
            {
                for (int h = 0; h < min(4, (int)B[i].size()); h++)
                {
                    for (int k = 0; k < min(4, (int)A[j].size()); k++)
                    {
                        int v = B[i][h], u = A[j][k];
                        if (v != u && v != j && u != i)
                            if (tot < D[v][i] + D[i][j] + D[j][u])
                                tot = D[v][i] + D[i][j] + D[j][u], R.clear(), R.pb(v), R.pb(i), R.pb(j), R.pb(u);
                    }
                }
            }
    for (auto X : R)
        printf("%d ", X);
    return (0);
}