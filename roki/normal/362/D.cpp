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

int n, m, p, q;
pair<int, int> other;
vector<pair<int, int> > g[100000];
bool read()
{
    if (!(cin >> n >> m >> p >> q))
        return false;
    forn (i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
        other = mp(a + 1, b + 1);
    }
    return true;
}

int pp[100000];
li sum[100000];
bool used[100000];

void dfs(int v)
{
    used[v] = true;
    forn (i, g[v].size())
    {
        int to = g[v][i].first;
        int w = g[v][i].second;
        sum[pp[v]] += w;
        if (!used[to])
        {
            pp[to] = pp[v];
            dfs(to);
        }
    }
}

void solve()    
{
    int cnt = 0;
    set<pair<li, int> > obl;
    forn (i, n)
    {
        if (!used[i])
        {
            cnt++;
            pp[i] = i;
            dfs(i);
            sum[i] /= 2;
            obl.insert(mp(sum[i], i));
        }
    }
    if (cnt < q)
    {
        cout << "NO";
        return;
    }
    vector<pair<int, int> > ans;
    while (cnt > q)
    {
        p--;
        cnt--;
        pair<int, int> ft = *obl.begin();
        obl.erase(obl.begin());
        pair<int, int> sc = *obl.begin();
        obl.erase(obl.begin());
        sum[ft.second] += sum[sc.second];
        li len = min(sum[ft.second] + 1, li(1e9));
        sum[ft.second] += len;
        ans.pb(mp(ft.second + 1, sc.second + 1));
        obl.insert(mp(sum[ft.second], ft.second));
        other = mp(ft.second + 1, sc.second + 1);
    }
    if (n == 1 && p != 0)
    {
        cout << "NO";
        return;
    }
    if (p < 0 || cnt == n && p > 0 || p > 0 && other.first == 0)
    {
        cout << "NO";
        return;
    }
    forn (i, p)
        ans.pb(other);
    cout << "YES" << endl;
    forn (i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << endl;
}
    
int main()
{
#ifdef SU6
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
        read();
        solve();
    return 0;
}