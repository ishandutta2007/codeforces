// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 300005, SGM = 26;
int n, ts = 1, A[N], F[N], SZ[N], C[N][SGM];
char S[N];
vector < int > Adj[N];
vector < pair < int , int > > V;
inline bool CMP(int i, int j)
{
    return (SZ[i] > SZ[j]);
}
void DFSSZ(int v, int p)
{
    SZ[v] = 1;
    for (int i = 0; i < (int)Adj[v].size(); i ++)
        if (Adj[v][i] == p)
            Adj[v].erase(Adj[v].begin() + i);
    for (int u : Adj[v])
        DFSSZ(u, v), SZ[v] += SZ[u];
    sort(Adj[v].begin(), Adj[v].end(), CMP);
}
void Add(int v, int root)
{
    for (int u : Adj[v])
    {
        if (!C[root][S[u]])
            C[root][S[u]] = ++ ts;
        Add(u, C[root][S[u]]);
    }
}
int DFS(int v)
{
    int root = 1;
    if (Adj[v].size())
    {
        for (int u : Adj[v])
            if (u != Adj[v][0])
            {
                DFS(u);
                for (int i = 0; i <= ts; i ++)
                    for (int j = 0; j < SGM; j ++)
                        C[i][j] = 0;
                ts = 1;
            }
        int ch = DFS(Adj[v][0]);
        root = ++ ts;
        C[root][S[Adj[v][0]]] = ch;
        for (int u : Adj[v])
            if (u != Adj[v][0])
            {
                if (!C[root][S[u]])
                    C[root][S[u]] = ++ ts;
                Add(u, C[root][S[u]]);
            }
    }
    F[v] = A[v] + ts;
    return (root);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    scanf("%s", &S[1]);
    for (int i = 1; i < n; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        Adj[v].push_back(u);
        Adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++)
        S[i] -= 'a';
    DFSSZ(1, 0);
    DFS(1);
    int Cnt = 0, MX = * max_element(F + 1, F + n + 1);
    for (int i = 1; i <= n; i ++)
        if (F[i] == MX)
            Cnt ++;
    return !printf("%d\n%d\n", MX, Cnt);
}