#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<ld, ld> pt;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ft first
#define sc second
#define x first
#define y second

const int INF = 1e9;
const ld EPS = 1e-10;

int n, m;
const int N = 2000;
vector<int> g[N];
vector<int> p;

bool read()
{
    if (!(cin >> n >> m))
        return false;

    p.resize(n);

    forn (i, n)
        cin >> p[i];

    forn (i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    return true;
}

set<pair<int, int> > s;

bool done[N];

int del (int v)
{
    int res = 0;
    forn (i, g[v].size())
    {
        int to = g[v][i];
        if (!done[to])
            res += p[to];
    }
    return res;
}

void solve() 
{
    forn (i, n)
        s.insert(mp(-p[i], i));

    int ans = 0;

    while(!s.empty())
    {
        ans += del(s.begin()->second);
        done[s.begin()->second] = true;
        s.erase(s.begin());
    }

    cout << ans << endl;

}   

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    read();
    solve();

    return 0;
}