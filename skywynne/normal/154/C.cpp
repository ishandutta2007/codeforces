#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 3;
int n, m;
long long tot;
vector < int > Adj[N], A[N];
map < vector < int > , int > M;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, v, u; i < m; i++)
        scanf("%d%d", &v, &u), Adj[v].pb(u), Adj[u].pb(v);
    for (int i = 1; i <= n; i++)
        sort(Adj[i].begin(), Adj[i].end()), A[Adj[i].size()].pb(i);
    for (int i = 0; i <= n; i++)
        if (A[i].size())
        {
            for (int &id : A[i])
                M[Adj[id]] ++;
            for (auto &X : M)
                tot += 1ll * X.second * (X.second - 1);
            M.clear();
            for (int &id : A[i])
            {
                auto it = lower_bound(Adj[id].begin(), Adj[id].end(), id);
                Adj[id].insert(it, id); M[Adj[id]] ++;
            }
            for (auto &X : M)
                tot += 1ll * X.second * (X.second - 1);
            M.clear();
        }
    return !printf("%lld", tot >> 1);
}