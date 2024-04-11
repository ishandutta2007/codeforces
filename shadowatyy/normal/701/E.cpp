#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000LL
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PIC pair<int, char>
#define VI vector<int>
#define VLL vector<ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORD(x, y, z) for(int x = y; x >= (z); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define MAXN 200007
using namespace std;

int n, a, b, k;

ll res;

bitset<MAXN> u;

VI G[MAXN];

int sub[MAXN];

void dfs(int v, int f)
{
    if(u[v])
        ++sub[v];

    for(auto it: G[v])
    {
        if(it!=f)
        {
            dfs(it, v);
            res += min(2*k-sub[it], sub[it]);
            sub[v] += sub[it];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= 2*k; ++i)
    {
        cin >> a;

        u[a] = 1;
    }

    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;

        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(1, -1);

    cout << res;
}