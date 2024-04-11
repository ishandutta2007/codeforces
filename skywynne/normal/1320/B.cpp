// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, m, q, k, A[N], D[N];
vector < int > Adj[N], Adt[N];
inline void BFS(int st)
{
    queue < int > qu;
    memset(D, 63, sizeof(D));
    D[st] = 0; qu.push(st);
    while (qu.size())
    {
        int v = qu.front();
        qu.pop();
        for (int u : Adt[v])
            if (D[u] > D[v] + 1)
                D[u] = D[v] + 1, qu.push(u);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        cin >> v >> u;
        Adj[v].push_back(u);
        Adt[u].push_back(v);
    }
    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> A[i];
    BFS(A[k]);
    int Mn = 0, Mx = 0;
    for (int i = 1; i < k; i ++)
        if (D[A[i]] - 1 != D[A[i + 1]])
            Mn ++;
    for (int i = 1; i < k; i ++)
    {
        if (D[A[i]] - 1 != D[A[i + 1]])
            {Mx ++; continue;}
        int cnt = 0;
        for (int u : Adj[A[i]])
            if (D[u] == D[A[i]] - 1)
                cnt ++;
        if (cnt > 1)
            Mx ++;
    }
    printf("%d %d\n", Mn, Mx);
    return 0;
}