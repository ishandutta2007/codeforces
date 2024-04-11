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
const int N = 100005;
vector<int> g[N];
pair<int, int> p[N];

bool read()
{
    if (!(cin >> n >> m))
        return false;

    forn (i, n)
    {
        cin >> p[i].ft;
        p[i].sc = i;
    }

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

int l[N];
int sz[N];

int leader (int v)
{
    return l[v] == v ? v : l[v] = leader(l[v]);
}

li merge(int a, int b)
{
    a = leader(a);
    b = leader(b);
    if (a == b)
        return 0;
    if (sz[a] < sz[b])
        swap(a, b);
    li res = li(sz[a]) * li(sz[b]);
    l[b] = a, sz[a] += sz[b];

    return res;
}

bool added[N];

void solve() 
{
    ld sum = 0;

    forn (i, n)
        l[i] = i, sz[i] = 1;

    sort(p, p + n);

    forn (i, n)
    {
        int v = p[n - 1 - i].sc;
        forn (j, g[v].size())
        {
            int to = g[v][j];
            if (added[to])
                sum += merge(v, to) * ld(p[n - i - 1].ft);
        }
        added[v] = true;
    }

    cout << fixed << setprecision(10) << (sum / n) / (n - 1) * 2 << endl;
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