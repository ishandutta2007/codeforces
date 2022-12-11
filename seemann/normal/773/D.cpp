#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const ll INF = 1e18L;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 2100;

ll g[MAXN][MAXN];

int n;
vector<ll> getd(int st, int en) {
    vector<ll> d1(n, INF);
    vector<int> vs;
    forn(v, n) {
        if (v != en) {
            vs.pb(v);
        }
    }
    for (auto v : vs) {
        d1[v] = g[st][v];
    }
    vector<ll> d(n, INF);
    ll mnlen = g[st][en];
    ll add = (n - 2) * mnlen;
    for (auto v : vs) {
        for (auto u : vs) {
            if (u == v || v == st || u == st)
                continue;
            d[v] = min(d[v], min(g[st][u], g[u][v]) + g[u][v] - mnlen);
        }
    }
    /*
    forn(i, n) {
        cerr << d1[i] << ' ';
    }
    cerr << '\n';
    forn(i, n) {
        cerr << d[i] << ' ';
    }
    cerr << '\n';*/
    d[st] = 0;
    vector<bool> used(n, false);
    used[st] = true;
    forn(_, n - 2) {
        int mn = -1;
        for (auto v : vs) {
            if (!used[v] && (mn == -1 || d[mn] > d[v])) {
                mn = v;
            }
        }
        assert(mn >= 0);
        used[mn] = true;
        for (auto v : vs) {
            if (v == mn)
                continue;
            d[v] = min(d[v], d[mn] + g[mn][v] - mnlen);
        }
    }
    for (auto v : vs) {
        d[v] = min(d[v], d1[v]) + add;
    }
    d[st] += mnlen;
    return d;
}

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>> n;
    int mnu = -1, mnv = -1;
    forn(i, n) {
        g[i][i] = 0;
        forn(j, n - i - 1) {
            int u = i;
            int v = i + j + 1;
            cin >> g[u][v];
            if (mnu == -1 || g[mnu][mnv] > g[u][v]) {
                mnu = u;
                mnv = v;
            }
            g[v][u] = g[u][v];
        }
    }
    /*
    forn(i, n) {
        forn(j, n) {
            cerr << g[i][j] << ' ';
        }
        cerr << '\n';
    }
    cerr << mnu << ' ' << mnv << ' ' << g[mnu][mnv] << '\n';
*/
    vector<ll> d1 = getd(mnu, mnv);
    vector<ll> d2 = getd(mnv, mnu);
    forn(i, n) {
        cout << min(d1[i], d2[i]) << '\n';
    }

    return 0;
}