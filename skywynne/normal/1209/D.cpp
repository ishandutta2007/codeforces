// ItnoE
#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, C, V, E, M[N];
vector < int > Adj[N];
void DFS(int v)
{
    M[v] = 1;
    V ++; E += (int)Adj[v].size();
    for (int u : Adj[v])
        if (!M[u]) DFS(u);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int v, u; k; k --)
        scanf("%d%d", &v, &u), Adj[v].push_back(u), Adj[u].push_back(v);
    for (int i = 1; i <= n; i ++)
        if (!M[i])
            DFS(i), C += E / 2 - V + 1, E = V = 0;
    return !printf("%d\n", C);
}