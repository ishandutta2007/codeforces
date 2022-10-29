#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m;

struct edge
{
    int to, l, r;
};

vector<edge> g[1000];

edge me(int a, int l, int r)
{
    edge res;
    res.to = a;
    res.l = l;
    res.r = r;
    return res;
}

bool read()
{
    if (!(cin >> n >> m))
        return false;
    forn (i, m)
    {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        a--, b--;
        g[a].pb(me(b, l, r));
        g[b].pb(me(a, l, r));
    }
    return true;
}

void solve()    
{
    int ans = 0;
    forn (k, 1000)
        forn (u, g[k].size())
    {
        int low = g[k][u].l;
        vector<int> d(n, 0);
        set<pair<int, int> > cur;
        cur.insert(mp(1e9, 0));
        d[0] = 1e9;
        while (!cur.empty())
        {
            int v = cur.begin()->second;
            cur.erase(cur.begin());
            forn (i, g[v].size())
            {
                int to = g[v][i].to;
                int l = g[v][i].l, r = g[v][i].r;
                if (l <= low && d[to] < min(d[v], r))
                {
                    cur.erase(mp(-d[to], to));
                    d[to] = min(d[v], r);
                    cur.insert(mp(-d[to], to));
                }
            }
        }
        ans = max(ans, d[n - 1] - low + 1);
    }
    if (ans == 0)
        cout << "Nice work, Dima!" << endl;
    else
        cout << ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}