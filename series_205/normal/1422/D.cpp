// #include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

ll n, m;
ll sx, sy, tx, ty;

struct place {
    ll x, y, idx;
};

vector<place> ps;

struct edge {
    ll to, cost;
};

struct node {
    ll v;
    ll d;
    bool operator<(const node &r) const { return d > r.d; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> sx >> sy >> tx >> ty;

    ll S = m, T = m + 1;
    vector<vector<edge>> G(m + 2);

    G[S].push_back(edge{T, abs(sx - tx) + abs(sy - ty)});

    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        ps.push_back(place{x, y, i});
        G[S].push_back(edge{i, min(abs(sx - x), abs(sy - y))});
        G[i].push_back(edge{T, abs(x - tx) + abs(y - ty)});
    }

    sort(ALL(ps), [](auto a, auto b) { return a.x < b.x; });
    rep(i, m - 1) {
        G[ps[i].idx].push_back(edge{ps[i + 1].idx, ps[i + 1].x - ps[i].x});
        G[ps[i + 1].idx].push_back(edge{ps[i].idx, ps[i + 1].x - ps[i].x});
    }
    sort(ALL(ps), [](auto a, auto b) { return a.y < b.y; });
    rep(i, m - 1) {
        G[ps[i].idx].push_back(edge{ps[i + 1].idx, ps[i + 1].y - ps[i].y});
        G[ps[i + 1].idx].push_back(edge{ps[i].idx, ps[i + 1].y - ps[i].y});
    }

    vector<ll> d(m + 2, inf);
    d[S] = 0;
    priority_queue<node> que;
    que.push(node{S, 0});

    while(!que.empty()) {
        node v = que.top();
        que.pop();
        if(d[v.v] < v.d) continue;
        for(auto [to, cost] : G[v.v])
            if(chmin(d[to], v.d + cost)) que.push(node{to, d[to]});
    }

    cout << d[T] << endl;

    return 0;
}