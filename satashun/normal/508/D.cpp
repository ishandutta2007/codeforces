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

// directed
// destruct graph

template <class E>
V<int> EulerianPath(const int s, VV<E>& g) {
    auto dfs = [&](auto&& self, int u, V<int>& path) -> void {
        while (!g[u].empty()) {
            int v = g[u].back();  // E : int
            g[u].pop_back();
            self(self, v, path);
        }
        path.push_back(u);
    };
    V<int> path;
    dfs(dfs, s, path);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    map<string, int> id;
    V<string> vs;
    int now = 0;

    auto get_id = [&](string s) {
        if (!id.count(s)) {
            vs.pb(s);
            id[s] = now++;
        }
        return id[s];
    };

    V<pii> es;

    rep(i, n) {
        string s;
        cin >> s;
        int a = get_id(s.substr(0, 2));
        int b = get_id(s.substr(1, 2));
        debug(a, b);
        es.eb(a, b);
    }

    VV<int> g(now);
    V<int> indeg(now);
    for (auto p : es) {
        g[p.fi].pb(p.se);
        indeg[p.se]++;
    }
    int s = -1;
    int cnt = 0;
    bool ok = true;
    rep(i, now) {
        if (g[i].size() == indeg[i] + 1) {
            s = i;
            cnt++;
        }
        if (abs((int)g[i].size() - indeg[i]) >= 2) {
            ok = false;
        }
    }
    if (!ok || cnt > 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (s == -1) s = 0;
    auto vec = EulerianPath(s, g);
    debug(vec);
    string ans = vs[vec[0]];
    for (int i = 1; i < vec.size(); ++i) {
        ans.pb(vs[vec[i]].back());
    }
    if (ans.size() < n + 2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << ans << endl;

    return 0;
}