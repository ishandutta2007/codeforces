// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 300505;
int n, m, k, SZ[N];
vector < pair < int , int > > Adj[N];
long long MN, MX;
void DFS(int v, int p)
{
    SZ[v] = 1;
    for (auto u : Adj[v])
        if (u.first != p)
        {
            DFS(u.first, v);
            SZ[v] += SZ[u.first];
            if (SZ[u.first] & 1)
                MN += u.second;
            MX += 1LL * u.second * min(SZ[u.first], n - SZ[u.first]);
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (; q; q --)
    {
        cin >> k;
        n = k + k;
        for (int i = 1; i < n; i ++)
        {
            int v, u, w;
            cin >> v >> u >> w;
            Adj[v].push_back({u, w});
            Adj[u].push_back({v, w});
        }
        DFS(1, 0);
        printf("%lld %lld\n", MN, MX);
        MN = MX = 0;
        for (int i = 1; i <= n; i ++)
            Adj[i].clear();
    }
    return 0;
}