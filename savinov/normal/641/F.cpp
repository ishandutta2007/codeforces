#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

int nxt() {
    int x; scanf("%d", &x);
    return x;
}
const int N = 1002;
typedef bitset<N * 2> T;

vector < vector<int> > g, gt;
vector<bool> used;
vector<int> order, comp;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs1 (to);
    }
    order.push_back (v);
}

void dfs2 (int v, int cl) {
    comp[v] = cl;
    for (size_t i=0; i<gt[v].size(); ++i) {
        int to = gt[v][i];
        if (comp[to] == -1)
            dfs2 (to, cl);
    }
}

vi sol(int n, const vector<T>& a) {
    n *= 2;
    g.assign(n, vi());
    gt.assign(n, vi());
    forn (i, n) forn (j, n)
            if (a[i][j]) g[i].pb(j), gt[j].pb(i);
    order.clear();
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);

    comp.assign (n, -1);
    for (int i=0, j=0; i<n; ++i) {
        int v = order[n-i-1];
        if (comp[v] == -1)
            dfs2 (v, j++);
    }

    for (int i=0; i<n; ++i)
        if (comp[i] == comp[i^1]) {
            return vi();
        }
    vi ans(n/2);
    for (int i=0; i<n/2; i++) {
        ans[i] = comp[i * 2] > comp[i * 2 + 1] ? 1 : 0;
    }
    return ans;
}

vector<T> f(int n, int m) {
    vector<T> a(n*2);
    forn (i, m) {
        int u = nxt(), v = nxt();
        int x = (abs(u) - 1) * 2 + (u < 0);
        int y = (abs(v) - 1) * 2 + (v < 0);
        a[x ^ 1][y] = 1;
        a[y ^ 1][x] = 1;
    }
    forn (k, 2 * n)
        forn (i, 2 * n)
            if (a[i][k])
                a[i] |= a[k];
    return a;
}

bool check(const vi& a, const vector<T>& b) {
    forn (i, 2 * a.size())
        forn (j, 2 * a.size())
            if (a[i / 2] != i % 2 && a[j / 2] == j % 2 && b[i][j])
                return false;
    return true;
}

vi broad(const vector<T>& a, const vi& vals) {
    vi res = vals;
    queue<int> q;
    int n = vals.size();
    forn (i, n)
        if (vals[i] != -1) q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();

        forn (i, n * 2) {
            if (a[v * 2 + (res[v]^1)][i] && res[i / 2] == -1) {
                res[i / 2] = (i % 2) ^ 1;
                q.push(i / 2);
            }
        }
    }
    return res;
}

vi extend(const vi& to_extend, const vi &sol) {
    vi res = to_extend;
    forn(i, sol.size()) if (res[i] == -1) res[i] = sol[i];
    return res;
}

void print(const vi &sol) {
    for (int x : sol) cout << x << " ";
    cout << "\n";
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    //ios::sync_with_stdio(false);
    int n = nxt(), m1 = nxt(), m2 = nxt();
    vector<T> a = f(n, m1);
    vector<T> b = f(n, m2);

    if (a == b) {
        puts("SIMILAR");
        return 0;
    }
    vi sa = sol(n, a);
    vi sb = sol(n, b);
    if (sa.empty() != sb.empty()) {
        vi x = sa;
        if (x.empty()) x = sb;
        print(x);
    }
    if (sa.empty()) {
        puts("SIMILAR");
        return 0;
    }
    vi dta(n, -1);
    forn (i, n) {
        if (a[i * 2][i * 2 + 1])
            dta[i] = 0;
        if (a[i * 2 + 1][i * 2])
            dta[i] = 1;
    }
    dta = broad(a, dta);
    vi dtb(n, -1);
    forn (i, n) {
        if (b[i * 2][i * 2 + 1])
            dtb[i] = 0;
        if (b[i * 2 + 1][i * 2])
            dtb[i] = 1;
    }
    dtb = broad(b, dtb);

    forn(i, 2*n) forn(j, 2*n) if (a[i][j] != b[i][j]) forn(p, 2) forn(q, 2) {
                        vi s = dta;
                        s[i / 2] = p;
                        s[j / 2] = q;
                        s = extend(broad(a, s), sa);
                        if (check(s, a) != check(s, b)) print(s);
                        s = dtb;
                        s[i / 2] = p;
                        s[j / 2] = q;
                        s = extend(broad(b, s), sb);
                        if (check(s, a) != check(s, b)) print(s);
                    }
    puts("SIMILAR");
    return 0;
}