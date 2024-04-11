#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 1 << 18;

vector<pii> g[nmax];
vector<int> pre[nmax];
int lb[nmax], rb[nmax];
vector<pair<pii, int> > e;
int n, k;
int s[nmax], a[nmax];
int res[nmax];

void build(int v, int l, int r){
    lb[v] = e[l].fs.fs;
    rb[v] = e[r].fs.fs;
    g[v].clear();
    for (int i = l; i <= r; i ++)
        g[v].pb(mp(e[i].fs.sc, e[i].sc));
    sort(all(g[v]));
    pre[v].assign(g[v].size(), -1);
    for (int i = g[v].size() - 1; i >= 0; i --){
        pre[v][i] = g[v][i].sc;
        if (i + 1 < g[v].size())
            pre[v][i] = max(pre[v][i], pre[v][i+1]);
    }

    int mid = (l + r) / 2;
    if (l != r){
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
    }
}

int get(int v, int up){
    if (g[v][0].fs > up) return 0;
    int l = 0, r = g[v].size() - 1;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (g[v][mid].fs <= up)
            l = mid;
        else
            r = mid - 1;
    }
    return l + 1;
}

int get(int v, int l1, int r1, int up){
    if (lb[v] > r1 || rb[v] < l1)
        return 0;
    if (l1 <= lb[v] && rb[v] <= r1)
        return get(v, up);
    return get(v * 2, l1, r1, up) + get(v * 2 + 1, l1, r1, up);
}

int calc(int v, int down){
    if (g[v].size() == 0) return -1;
    if (g[v].back().fs < down) return -1;
    int l = 0, r = g[v].size() - 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (g[v][mid].fs >= down)
            r = mid;
        else
            l = mid + 1;
    }
    return pre[v][l];
}

int calc(int v, int l, int r, int down){
    if (lb[v] > r || rb[v] < l)
        return -1;
    if (l <= lb[v] && rb[v] <= r)
        return calc(v, down);
    return max(calc(v * 2, l, r, down), calc(v * 2 + 1, l, r, down));
}

int solve(int v, int u){
    if (a[v] > a[u])
        swap(v, u);
    int l = a[u] - k;
    int r = a[v] + k;
    int res = calc(1, l, r, max(s[v], s[u]));
    return res;
}

int main ()
{
    cin >> n >> k;
    forn(i, n)
        scanf("%d", &s[i]);
    forn(i, n)
        scanf("%d", &a[i]);
    forn(i, n)
        e.pb(mp(mp(a[i], s[i]), -1));
    sort(all(e));
    build(1, 0, n-1);
    forn(i, n){
        res[i] = get(1, a[i] - k, a[i] + k, s[i]);
    }
    e.clear();
    forn(i, n)
        e.pb(mp(mp(a[i], s[i]), res[i]));
    sort(all(e));
    build(1, 0, n-1);
    int tst;
    cin >> tst;
    forn(i, tst){
        int a, b;
        scanf("%d %d", &a, &b);
        a --; b--;
        printf("%d\n", solve(a, b));
    }

    return 0;
}