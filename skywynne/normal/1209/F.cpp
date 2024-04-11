// ItnoE
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 1000306, Mod = 1e9 + 7;
int n, m, ts, D[N], Q[N], M[N], R[N];
vector < pair < int , int > > Adj[N];
inline void Add(int v, int u, int w)
{
    while (w > 9)
        Adj[++ ts].push_back({v, w % 10}), v = ts, w /= 10;
    Adj[u].push_back({v, w});
}
void DFS(vector < int > A)
{
    for (int d = 0; d <= 9; d ++)
    {
        vector < int > B;
        for (int v : A)
            for (auto u : Adj[v])
                if (!M[u.x] && u.y == d)
                    R[u.x] = (R[v] * 10LL + u.y) % Mod, M[u.x] = 1, B.push_back(u.x);
        if (B.size()) DFS(B);
    }
}
int main()
{
    scanf("%d%d", &n, &m); ts = n;
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Add(v, u, i);
        Add(u, v, i);
    }
    int l = 0, r = 0;
    memset(D, 63, sizeof(D));
    D[1] = 0; Q[r ++] = 1;
    while (r - l)
    {
        int v = Q[l ++];
        for (auto u : Adj[v])
            if (D[u.x] > D[v] + 1)
                D[u.x] = D[v] + 1, Q[r ++] = u.x;
    }
    for (int v = 1; v <= ts; v ++)
    {
        for (int i = 0; i < Adj[v].size(); i ++)
            if (D[Adj[v][i].x] != D[v] + 1)
                swap(Adj[v][i], Adj[v].back()), Adj[v].pop_back(), i --;
    }
    M[1] = 1; DFS({1});
    for (int i = 2; i <= n; i ++)
        printf("%d\n", R[i]);
    return 0;
}