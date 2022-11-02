#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 5e5 + 10;
int n, Mn, ts, Fr[N], To[N], P[N], M[N];
vector < int > Lf;
set < pair < int , int > > S, Adj[N][2];
map < pair < int , int > , bool > MP;
int Find(int v)
{
    if (P[v] == v)
        return (v);
    return (P[v] = Find(P[v]));
}
void Merge(int v, int u)
{
    v = Find(v); u = Find(u);
    if (v == u) return ;
    if (Adj[v][0].size() + Adj[v][1].size() < Adj[u][0].size() + Adj[u][1].size())
        swap(v, u);
    P[u] = v;
    for (auto X : Adj[u][0])
        Adj[v][0].insert(X);
    for (auto X : Adj[u][1])
        Adj[v][1].insert(X);
    Adj[u][0].clear();
    Adj[u][1].clear();
}
pair < int , int > Get(int v, int w)
{
    if (!Adj[v][w].size()) return (make_pair(-1, -1));
    pair < int , int > ret = *Adj[v][w].begin();
    Adj[v][w].erase(Adj[v][w].begin());
    return (ret);
}
void Del(int v, int u, int w)
{
    int pv = Find(v), pu = Find(u);
    Adj[pv][w].erase({v, u});
    Adj[pu][w].erase({u, v});
}
int main()
{
    scanf("%d", &n); Mn = n - 1;
    for (int i = 1, v, u; i < n; i++)
        scanf("%d%d", &v, &u), Adj[v][0].insert({v, u}), Adj[u][0].insert({u, v}), MP[{v, u}] = MP[{u, v}] = 1;
    for (int i = 1; i < n; i++)
        scanf("%d%d", &Fr[i], &To[i]), Adj[Fr[i]][1].insert({Fr[i], To[i]}), Adj[To[i]][1].insert({To[i], Fr[i]});
    for (int i = 1; i <= n; i++)
        P[i] = i;
    for (int i = 1; i < n; i++)
        if (MP[{Fr[i], To[i]}])
        {
            Del(To[i], Fr[i], 0);
            Del(To[i], Fr[i], 1);
            Merge(Fr[i], To[i]);
            Mn --;
        }
    for (int i = 1; i <= n; i++)
        if (Find(i) == i)
            S.insert({(int)Adj[i][0].size(), i});
    printf("%d\n", Mn);
    while (S.size())
    {
        int lv = (*S.begin()).y; S.erase(S.begin());
        pair < int , int > to = Get(lv, 1), pr = Get(lv, 0);
        if (to.x == -1 || pr.x == -1) continue;
        printf("%d %d %d %d\n", pr.x, pr.y, to.x, to.y);
        S.erase({(int)Adj[Find(pr.y)][0].size(), Find(pr.y)});
        S.erase({(int)Adj[Find(to.y)][0].size(), Find(to.y)});
        Adj[Find(to.y)][1].erase({to.y, to.x});
        Adj[Find(pr.y)][0].erase({pr.y, pr.x});
        Merge(to.x, to.y);
        S.insert({(int)Adj[Find(pr.y)][0].size(), Find(pr.y)});
        if (Find(pr.y) != Find(to.y))
            S.insert({(int)Adj[Find(to.y)][0].size(), Find(to.y)});
    }
    return (0);
}