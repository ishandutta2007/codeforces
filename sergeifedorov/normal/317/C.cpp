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
#include <queue>

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

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 350;

int n, R, e;
int bufa[nmax];
int a[nmax], b[nmax], used[nmax];
vector<pii> w;
vector<int> g[nmax];
int p[nmax], pr[nmax];
vector<pair<pii, int> > res;

int64 sa[nmax], sb[nmax];

void write() {
    cout << res.size() << endl;
    forn(i, res.size())
        printf("%d %d %d\n", res[i].fs.fs + 1, res[i].fs.sc + 1, res[i].sc);
    exit(0);
}

int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
}

void merge(int v, int u) {
    v = get(v);
    u = get(u);
    if (rand() & 1)
        p[v] = u;
    else
        p[u] = v;
}

void add(int x, int y) {
    w.pb(mp(x, y));
}

void gen() {
    forn(i, n)
        p[i] = i;
    random_shuffle(all(w));
    forn(i, w.size()) {
        int v = w[i].fs;
        int u = w[i].sc;
        if (get(v) == get(u)) continue;
        g[v].pb(u);
        g[u].pb(v);
        merge(v, u);
    }
}



void no() {
    puts("NO");
    exit(0);
}

void dfs(int v, int p) {
    pr[v] = p;
    used[v] = 1;
    sa[v] = a[v];
    sb[v] = b[v];
    forn(i, g[v].size()) {
        int u = g[v][i];
        if (!used[u]) {
            dfs(u, v);
            sa[v] += sa[u];
            sb[v] += sb[u];
        }
    }
}

int64 calc(int v, int u) {
    if (sa[v] > sb[v]) {
        int64 res = min(a[v], R - a[u]);
        res = min(res, sa[v] - sb[v]);
        return max(res, 0ll);
    } else {
        int64 res = min(a[u], R - a[v]);
        res = min(res, sb[v] - sa[v]);
        return max(res, 0ll);
    }                      
}

void move(int v, int u, int cn) {
    if (sa[v] > sb[v]) {
        sa[v] -= cn;
        a[v] -= cn;
        a[u] += cn;
        res.pb(mp(mp(v, u), cn));   
    } else {
        sa[v] += cn;
        a[v] += cn;
        a[u] -= cn; 
        res.pb(mp(mp(u, v), cn));   
    }                      
}

void do_solve() {
    memset(used, 0, sizeof used);
    vector<int> qwe;
    forn(i, n)
        qwe.pb(i);
    random_shuffle(all(qwe));
    forn(i, n)
        if (!used[qwe[i]])
            dfs(qwe[i], -1);
    res.clear();
    while(1) {
        pii pos = mp(-1, -1);
        int cn = 0;
        forn(i, n)
            if (pr[i] != -1) {
                int now = calc(i, pr[i]);
                if (now > cn) {
                    cn = now;
                    pos = mp(i, pr[i]);
                }
            }
        if (cn == 0) break;
        move(pos.fs, pos.sc, cn);
            if (res.size() > 2 * n * n) return;
    }
    forn(i, n)
        if (a[i] != b[i])
            no();
        if (res.size() > 2 * n * n) return;
//      if (pr[0] != -1) return;
        write();
}

void solve() {
    forn(i, n)
        bufa[i] = a[i];
    while(1) {
        forn(i, n) {
            a[i] = bufa[i];
            g[i].clear();
        }
        gen();
        do_solve();
    }
}
int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> R >> e;
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, n) {
        cin >> b[i];
        p[i] = i;
    }
    forn(i, e) {
        int x, y;
        scanf("%d %d", &x, &y);
        x --;
        y --;
        add(x, y);
    }   
    solve();

    return 0;
}