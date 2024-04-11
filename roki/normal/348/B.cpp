#pragma comment(linker, "/STACK:167177216")
 
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
int a[100010];
vector<int> g[100010];
 
inline bool read()
{
    if(!(cin >> n))
        return false;
    forn (i, n)
        scanf("%d", &a[i]);
    forn (i, n - 1)
    {
        int q, b;
        scanf("%d%d", &q, &b);
        q--, b--;
        g[q].pb(b);
        g[b].pb(q);
    }
    return true;
}
 
li gcd(li a, li b)
{
    return b == 0 ? a : gcd(b, a % b);
}
 
bool ok = true;
li sum = 0;
 
li dfs(int v, int from = -1)
{
    li res = g[v].size() - 1;
    if(v == 0)
        res++;
    li mult = 1;
    forn (i, g[v].size())
    {
        if(from == g[v][i])
            continue;
        li to = dfs(g[v][i], v);
        if(to > sum)
            ok = false;
        mult *= to / gcd(to, mult);
        if(mult * res > sum || mult * res < 0)
            ok = false;
    }
    return max(mult * res, 1LL);
}
 
bool f(li m)
{
    queue<pair<li, int> > q;
    q.push(mp(m, 0));
    queue<int> fr;
    fr.push(-1);
    while(!q.empty())
    {
        int from = fr.front();
        fr.pop();
        int v = q.front().second;
        if(g[v].size() == 1 && v != 0 && q.front().first > a[v])
            return false;
        li val = q.front().first;
        q.pop();
        if(g[v].size() == 1 && v != 0)
            continue;
        val /= (g[v].size() - 1 + (v == 0));
        forn (i, g[v].size())
        {
            if(g[v][i] == from)
                continue;
            q.push(mp(val, g[v][i]));
            fr.push(v);
        }
    }
    return true;
}
 
inline void solve()
{
    forn (i, n)
        sum += a[i];
    li k = dfs(0);
    cerr << k << endl;
    if(!ok)
    {
        cout << sum << endl;
        return;
    }
    li l = 0, r = 1e18 / k;
    while(r - l > 1)
    {
        li m = (r + l) / 2;
        if(f(m * k))
            l = m;
        else
            r = m;
    }
    while(f((l + 1) * k))
        l++;
    cout << sum - l * k << endl;
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