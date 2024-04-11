#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

// O(V^2 E)
struct Dinic {
    using F = ll;
    static constexpr F INF = numeric_limits<F>::max();

    struct Edge {
        int to, rev;
        F cap;
        Edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev){};
    };

    using E = Edge;

    VV<E> g;
    V<int> level, iter;

    Dinic() {}
    Dinic(int n) : g(n), level(n), iter(n) {}

    void add_edge(int from, int to, F cap) {
        g[from].emplace_back(to, cap, (int)g[to].size());
        g[to].emplace_back(from, 0, (int)g[from].size() - 1);
    }

    void bfs(int s) {
        fill(ALL(level), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    F dfs(int v, int t, F f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                F d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    F max_flow(int s, int t) {
        F flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(ALL(iter), 0);
            F f;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }
};

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

map<pair<pii, pii>, int> id;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    V<string> s(n);
    rep(i, n) cin >> s[i];

    auto get_id = [&](pii p, pii q) {
        if (p > q) swap(p, q);
        int sz = id.size();
        if (!id.count(mp(p, q))) {
            id[mp(p, q)] = sz;
        }
        return id[mp(p, q)];
    };

    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '.') continue;
            V<pair<int, pii>> vec;
            rep(dir, 4) {
                int ni = i + dr[dir], nj = j + dc[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    s[ni][nj] == '#') {
                    int x = get_id(mp(i, j), mp(ni, nj));
                }
            }
            int sz = vec.size();
            rep(a, sz) {
                rep(b, sz) {
                    if (vec[a].fi % 2 == 0 && vec[b].fi % 2 == 1) {
                    }
                }
            }
        }
    }
    int now = id.size();
    Dinic g(now + 2);
    int vs = now, vt = vs + 1;

    const int INF = TEN(9);

    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '.') continue;
            V<pair<int, pii>> vec;
            rep(dir, 4) {
                int ni = i + dr[dir], nj = j + dc[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    s[ni][nj] == '#') {
                    vec.eb(dir, mp(ni, nj));
                }
            }
            int sz = vec.size();
            rep(a, sz) {
                rep(b, sz) {
                    if (vec[a].fi % 2 == 0 && vec[b].fi % 2 == 1) {
                        int p = get_id(mp(i, j), vec[a].se);
                        int q = get_id(mp(i, j), vec[b].se);
                        g.add_edge(q, p, INF);
                    }
                }
            }
        }
    }

    for (auto pr : id) {
        pii p = pr.fi.fi, q = pr.fi.se;
        if (p.fi == q.fi) {
            g.add_edge(pr.se, vt, 1);
        } else {
            g.add_edge(vs, pr.se, 1);
        }
    }

    int dec = id.size() - g.max_flow(vs, vt);
    int ans = 0;
    rep(i, n) rep(j, m) if (s[i][j] == '#') ans++;
    debug(ans, dec);
    cout << ans - dec << endl;

    return 0;
}