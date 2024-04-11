#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, bad, A[N], T[N];
bool R[N], S[N];
vector < int > Adj[N];
inline bool F(int v, bool a, bool b = 0)
{
    if (T[v] == 4)
        return (a);
    if (T[v] == 3)
        return (!a);
    if (T[v] == 0)
        return (a & b);
    if (T[v] == 1)
        return (a | b);
    if (T[v] == 2)
        return (a ^ b);
}
void DFS(int v)
{
    if (T[v] < 4)
        DFS(Adj[v][0]);
    if (T[v] < 3)
        DFS(Adj[v][1]);
    if (T[v] < 3)
        S[v] = F(v, S[Adj[v][0]], S[Adj[v][1]]);
    if (T[v] == 3)
        S[v] = F(v, S[Adj[v][0]]);
    if (T[v] == 4)
        S[v] = Adj[v][0];
}
void DFS2(int v)
{
    if (T[v] == 3)
    {
        DFS2(Adj[v][0]);
        return ;
    }
    if (T[v] == 4)
    {
        if (bad)
            R[v] = S[1];
        else
            R[v] = !S[1];
        return ;
    }
    for (int i = 0; i < 2; i++)
    {
        int u = Adj[v][0], w = Adj[v][1];
        if (F(v, !S[u], S[w]) == S[v])
            bad ++;
        DFS2(u);
        if (F(v, !S[u], S[w]) == S[v])
            bad --;
        swap(Adj[v][0], Adj[v][1]);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char ss[5]; int a, b;
        scanf("%s%d", &ss, &a);
        Adj[i].pb(a);
        if (ss[0] == 'A')
            scanf("%d", &b), T[i] = 0, Adj[i].pb(b);
        if (ss[0] == 'O')
            scanf("%d", &b), T[i] = 1, Adj[i].pb(b);
        if (ss[0] == 'X')
            scanf("%d", &b), T[i] = 2, Adj[i].pb(b);
        if (ss[0] == 'N')
            T[i] = 3;
        if (ss[0] == 'I')
            T[i] = 4;
    }
    DFS(1); DFS2(1);
    for (int i = 1; i <= n; i++)
        if (T[i] == 4)
            printf("%d", (int)R[i]);
    return (0);
}