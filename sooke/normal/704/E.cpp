#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const long double eps = 1e-12L, Eps = 1e-7L, inf = 1e18;
const int N = 2e5 + 5, V = 1e7 + 5;

long double _;

struct Segment {
    long double s, t, l, c;
    int i;

    inline long double r() const {
        return l + (_ - s) * c;
    }
};

bool operator <(const Segment &i, const Segment &j) {
    return std::abs(i.r() - j.r()) < eps ? i.i < j.i : i.r() < j.r();
}

long double ans;
int n, m, ft[N], dep[N], siz[N], hs[N], top[N], tms, dfn[N], opt[V];
std::vector<std::pair<long double, int>> b;
std::vector<int> e[N];
std::vector<Segment> a;
std::set<Segment> f;

void dfs1(int u, int fa) {
    ft[u] = fa; dep[u] = dep[fa] + 1; siz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) { continue; }
        dfs1(v, u); siz[u] += siz[v];
        if (siz[hs[u]] < siz[v]) { hs[u] = v; }
    }
}
void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++tms;
    if (hs[u] > 0) { dfs2(hs[u], tp); }
    for (auto v : e[u]) {
        if (v == ft[u] || v == hs[u]) { continue; }
        tms++; dfs2(v, v);
    }
}

int findLca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            u = ft[top[u]];
        } else {
            v = ft[top[v]];
        }
    }
    return dep[u] < dep[v] ? u : v;
}
int distance(int u, int v) {
    return dep[u] + dep[v] - dep[findLca(u, v)] * 2;
}

void update(Segment i, Segment j) {
    if (i.i == -1 || j.i == -1) { return; }
    long double d = j.r() - i.r();
    long double c = i.c - j.c;
    if (std::abs(c) < eps) {
        if (std::abs(d) < eps) {
            ans = std::min(ans, _);
        }
        return;
    }
    long double t = _ + d / c;
    if (t < i.s - eps || t < j.s - eps) { return; }
    if (t > i.t + eps || t > j.t + eps) { return; }
    ans = std::min(ans, t);
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v); e[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    for (int i = 0; i < m; i++) {
        long double s = read(), c = read(), t, _s, _t;
        int u = read(), v = read(), _u, _v;
        t = s + distance(u, v) / c;
        while (top[u] != top[v]) {
            _u = ft[top[u]]; _v = ft[top[v]];
            if (dep[_u] > dep[_v]) {
                _s = s + (dep[u] - dep[_u]) / c;
                a.push_back((Segment) {s, _s, dfn[u] + 0.0L, -c, a.size()});
                u = _u; s = _s;
            } else {
                _t = t - (dep[v] - dep[_v]) / c;
                a.push_back((Segment) {_t, t, dfn[top[v]] - 1.0L, c, a.size()});
                v = _v; t = _t;
            }
        }
        if (dep[u] > dep[v]) {
            a.push_back((Segment) {s, t, dfn[u] + 0.0L, -c, a.size()});
        } else {
            a.push_back((Segment) {s, t, dfn[u] + 0.0L, c, a.size()});
        }
    }
    ans = inf;
    f.insert((Segment) {0.0L, 0.0L, -inf, 0.0L, -1});
    f.insert((Segment) {0.0L, 0.0L, +inf, 0.0L, -1});
    for (int i = 0; i < a.size(); i++) {
        a[i].t += eps * 9;
        b.push_back({a[i].s, i}); b.push_back({a[i].t, i});
    }
    std::sort(b.begin(), b.end());
    for (auto p : b) {
        int i = p.second;
        _ = p.first; opt[i]++;
        if (_ > ans - Eps) { printf("%.6f\n", (double) ans); return 0; }
        if (opt[i] == 1) {
            auto it = f.insert(a[i]).first;
            auto l = it; update(a[i], *(--l));
            auto r = it; update(a[i], *(++r));
        } else {
            auto r = f.erase(f.lower_bound(a[i]));
            auto l = r; update(*(--l), *r);
        }
    }
    if (ans > inf / 2) { printf("-1\n"); return 0; }
    printf("%.6f\n", (double) ans);
    return 0;
}