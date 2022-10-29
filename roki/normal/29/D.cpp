#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
vector<int> g[300];

bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return true;
}

bitset<301> ch[301];
int lev = 0;
bool used[301];

void dfs1(int v, int p = -1)
{
    if(used[v])
        return;
    used[v] = true;
    forn (i, g[v].size())
    {
        int to = g[v][i];
        if(to == p)
            continue;
        dfs1(to, v);
        ch[v] |= ch[to];
        ch[v][to] = true;
    }
    if(ch[v].count() == 0)
        lev++;
}

vector<int> pr;
int ft = 0;
vector<int> ans;

void dfs2(int v, int p = -1)
{
    if(used[v])
        return;
    used[v] = true;
    ans.pb(v + 1);
    forn (j, lev)
    forn (i, g[v].size())
    {
        int to = g[v][i];
        if(to != pr[ft])
        if(to == p || ch[to][pr[ft]] != true)
            continue;
        dfs2(to, v);
        ans.pb(v + 1);
    }
    if(v == pr[ft])
        ft++;
}

void solve()
{
    dfs1(0);
    pr.resize(lev);
    forn (i, lev)
    {
        int a;
        cin >> a;
        a--;
        pr[i] = a;
    }
    pr.pb(300);
    memset(used, false, sizeof used);
    dfs2(0);
    if(ft != lev)
        cout << -1 << endl;
    else
        forn (i, ans.size())
            cout << ans[i] << ' ';
}

int main() {
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}