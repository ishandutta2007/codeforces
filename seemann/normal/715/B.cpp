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

const ll INF = 1e18 + 100;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 2100;
const int MAXM = 22000;

struct edge {
    int from, to, w;
};
int n;
ll d[MAXN];
int p[MAXN];
vector<int> g[MAXN];
edge e[MAXM];
bool c[MAXM], tr[MAXM];
struct comp {
    bool operator () (int a, int b) {
        if (d[a] != d[b])
            return d[a] < d[b];
        return a < b;
    }
};

void dijkstra(int st) {
    forn(i, n) {
        d[i] = INF;
        p[i] = -1;
    }
    d[st] = 0;
    set<ll, comp> s;
    s.insert(st);
    while (!s.empty()) {
        int cur = *s.begin();
        s.erase(s.begin());
        for (auto i : g[cur]) {
            edge ed = e[i];
            int to = ed.to;
            if (to == cur)
                to = ed.from;

            if (ed.w != 0 && d[to] > d[cur] + ed.w) {
                s.erase(to);
                d[to] = d[cur] + ed.w;
                p[to] = i;
                s.insert(to);
            }
        }
    }
}




int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int m;
    scanf("%d%d", &n, &m);
    int l, s, t;
    scanf("%d%d%d", &l, &s, &t);
    forn(i, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(i);
        g[v].push_back(i);;
        e[i] = {u, v, w};

    }
    
    dijkstra(s);
    if (d[t] < l) {
        printf("NO\n");
        return 0;
    }
    forn(i, m) {
        if (e[i].w == 0) {
            e[i].w = 1;
            c[i] = true;
        }
    }
    dijkstra(s);
    int v;
    for (v = t; p[v] != -1;) {
        tr[p[v]] = true;
        int nxt = e[p[v]].from;
        if (nxt == v)
            nxt = e[p[v]].to;
        v = nxt;
    }
    forn(i, m) {
        if (c[i] && !tr[i]) {
            e[i].w = l + 1;
            c[i] = false;
        }
    }
    while (true) {
        dijkstra(s);
        if (d[t] > l) {
            printf("NO\n");
            return 0;
        }
        if (d[t] == l) {
            break;
        }
        for (v = t; !c[p[v]];) {
            int nxt = e[p[v]].from;
            if (nxt == v)
                nxt = e[p[v]].to;
            v = nxt;
        }
        c[p[v]] = false;
        e[p[v]].w += l - d[t];
    }
    printf("YES\n");
    forn(i, m)
        printf("%d %d %d\n", e[i].from, e[i].to, e[i].w);

    
    return 0;
}