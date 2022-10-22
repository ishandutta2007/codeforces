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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    VV<pii> g(n);

    rep(i, m) {
        int a, b, x;
        cin >> a >> b >> x;
        --a, --b;
        g[a].eb(b, x);
        g[b].eb(a, x);
    }

    V<pii> tr;

    rep(i, k) {
        int s, y;
        cin >> s >> y;
        --s;
        g[0].eb(s, y);
        g[s].eb(0, y);
        tr.eb(s, y);
    }

    const ll INF = TEN(18);
    V<ll> d(n, INF);
    using Data = pair<ll, int>;
    priority_queue<Data, V<Data>, greater<Data>> que;
    que.emplace(0, 0);
    d[0] = 0;

    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.se;
        if (d[v] < p.fi) continue;
        for (auto e : g[v]) {
            ll nd = d[v] + e.se;
            if (nd < d[e.fi]) {
                d[e.fi] = nd;
                que.emplace(nd, e.fi);
            }
        }
    }

    debug(d);
    V<int> in(n);
    rep(v, n) {
        for (auto e : g[v]) {
            if (d[e.fi] == d[v] + e.se) {
                in[e.fi]++;
            }
        }
    }

    debug(in);

    int ans = 0;
    for (auto t : tr) {
        int v = t.fi, w = t.se;
        if (d[v] < w) {
            ans++;
        } else {
            if (in[v] > 1) ans++;
            in[v]--;
        }
    }
    cout << ans << endl;

    return 0;
}