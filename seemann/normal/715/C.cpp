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

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5 + 1000;

struct edge {
    int to, w;
};
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
vector<edge> g[MAXN];
ll p[MAXN], q[MAXN];
int d[MAXN];

int M;
ll p10[MAXN], ip10[MAXN];
ll inv(ll x) {
    ll c1, c2;
    gcd(x, M, c1, c2);
    return (c1 % M + M) % M;
}

void calc(int v, int par) {
    for (auto e : g[v]) {
        if (e.to == par)
            continue;
        d[e.to] = d[v] + 1;
        p[e.to] = (p[v] * 10 + e.w) % M; 
        q[e.to] = (q[v] + e.w * p10[d[v]])%M;
        calc(e.to, v);
    }
}

ll ans = 0;
struct dict {
    map<int, int> p, q;
    int size() {
        return p.size();
    }
};
dict* a[MAXN];
ll getmod(ll x) {
    x %= M;
    if ( x < 0)
        x += M;
    return x;
}
void getans(int v, int par) {
    a[v] = new dict();
    a[v]->p[getmod(p[v] * ip10[d[v]])]++;
    a[v]->q[q[v]]++;
    for (auto e : g[v]) {
        if (e.to == par)
            continue;
        getans(e.to, v);
        dict * b = a[e.to];
        if (a[v]->size() < b->size())
            swap(a[v], b);
        for (map<int, int>::iterator it = b->p.begin(); it != b->p.end(); it++) {
            ll c = getmod((q[v] - p10[d[v]] * ((-p[v] + it->first * p10[d[v]]) % M)));
            ans += ((ll)(a[v]->q[c])) * it->second;
        }
        for (map<int, int>::iterator it = b->q.begin(); it != b->q.end(); it++) {
            ll c = getmod(-((it->first - q[v]) * ip10[d[v]] %M- p[v] ) * ip10[d[v]]);
            ans += ((ll)(a[v]->p[c])) * it->second;
        }

        for (map<int, int>::iterator it = b->p.begin(); it != b->p.end(); it++) {
            a[v]->p[it->first] += it->second;
        }
        for (map<int, int>::iterator it = b->q.begin(); it != b->q.end(); it++) {
            a[v]->q[it->first] += it->second;
        }
    }
}


int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
    scanf("%d%d", &n, &M);
    forn(i, n - 1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    p10[0] = 1;
    ip10[0] = 1;
    forn(i, n) {
        p10[i + 1] = p10[i] * 10 % M;
        ip10[i + 1] = inv(p10[i + 1]);
    }
    d[0] = p[0] = q[0] = 0;
    calc(0, -1);
    forn(i, n)
        cerr << i << ' ' << d[i] << ' ' << p[i] << ' ' << q[i] << '\n';
    getans(0, -1);
    cout << ans << '\n';
    

    return 0;
}