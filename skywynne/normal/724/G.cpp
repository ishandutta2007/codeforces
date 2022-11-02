#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 100005, LG = 60, Mod = 1e9 + 7;
int n, m, C[LG][2];
ll X[N];
bool M[N];
vector < ll > base;
vector < pair < int , ll > > Adj[N];
void DFS(int v, int p)
{
    M[v] = 1;
    for (int i = 0; i < LG; i++)
        C[i][X[v] >> i & 1] ++;
    for (auto &u : Adj[v])
    {
        if (u.x == p)
            continue;
        if (M[u.x])
        {
            ll a = X[v] ^ X[u.x] ^ u.y;
            for (ll &b : base)
                a = min(a, a ^ b);
            for (ll &b : base)
                b = min(b, b ^ a);
            if (a) base.pb(a);
        }
        if (!M[u.x])
            X[u.x] = X[v] ^ u.y, DFS(u.x, v);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int v, u;
        ll w;
        scanf("%d%d%lld", &v, &u, &w);
        Adj[v].pb({u, w});
        Adj[u].pb({v, w});
    }
    ll tot = 0;
    for (int i = 1; i <= n; i++)
        if (!M[i])
        {
            DFS(i, 0);
            ll orr = 0;
            for (ll &a : base)
                orr |= a;
            for (int j = 0; j < LG; j++)
            {
                ll _n = C[j][0] + C[j][1];
                ll cnt = (ll)C[j][0] * C[j][1] % Mod;
                ll cf = (1LL << j) % Mod * ((1LL << (int)base.size()) % Mod) % Mod;
                if (orr >> j & 1)
                    tot = (tot + cf * (_n * (_n - 1) / 2 % Mod) % Mod * (Mod + 1) / 2) % Mod;
                else
                    tot = (tot + cf * cnt) % Mod;
            }
            memset(C, 0, sizeof(C));
            base.clear();
        }
    return !printf("%lld", tot);
}