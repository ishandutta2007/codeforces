//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    explicit operator int() const { return v; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    friend istream& operator>>(istream& in, M& x) {
        ll v_;
        in >> v_;
        x = M(v_);
        return in;
    }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const ll INF = TEN(18);

const int maxn = 200010;
ll d[maxn][20];
pair<int, int> dx[maxn][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    VV<int> g(n), rg(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        rg[b].pb(a);
    }

    {
        rep(i, n) rep(j, 20) d[i][j] = INF;
        d[0][0] = 0;
        using Data = pair<ll, pii>;

        priority_queue<Data, V<Data>, greater<Data>> que;
        que.emplace(0, mp(0, 0));

        while (!que.empty()) {
            auto t = que.top();
            que.pop();
            int v, k;
            tie(v, k) = t.se;
            if (d[v][k] < t.fi) continue;

            if (k < 19) {
                ll nd = d[v][k] + (1ll << k);
                if (nd < d[v][k + 1]) {
                    d[v][k + 1] = nd;
                    que.emplace(nd, mp(v, k + 1));
                }
            }

            for (auto to : (k % 2 == 0 ? g[v] : rg[v])) {
                ll nd = d[v][k] + 1;
                if (nd < d[to][k]) {
                    d[to][k] = nd;
                    que.emplace(nd, mp(to, k));
                }
            }
        }

        ll ans = INF;
        rep(i, 20) {
            if (d[n - 1][i] != INF) {
                chmin(ans, d[n - 1][i]);
            }
        }
        if (ans != INF) {
            cout << Mint(ans) << endl;
            return 0;
        }
    }

    rep(i, n) rep(j, 2) dx[i][j] = mp(1e9, 1e9);
    using Data = pair<pii, pii>;
    priority_queue<Data, V<Data>, greater<Data>> que;
    dx[0][0] = mp(0, 0);
    que.emplace(mp(0, 0), mp(0, 0));

    while (!que.empty()) {
        auto t = que.top();
        que.pop();
        int v, k;
        tie(v, k) = t.se;
        if (dx[v][k] < t.fi) continue;

        int rev, es;
        tie(rev, es) = t.fi;

        {
            if (mp(rev + 1, es) < dx[v][k ^ 1]) {
                dx[v][k ^ 1] = mp(rev + 1, es);
                que.emplace(mp(rev + 1, es), mp(v, k ^ 1));
            }
        }

        for (auto to : (k == 0 ? g[v] : rg[v])) {
            if (mp(rev, es + 1) < dx[to][k]) {
                dx[to][k] = mp(rev, es + 1);
                que.emplace(mp(rev, es + 1), mp(to, k));
            }
        }
    }
    auto p = min(dx[n - 1][0], dx[n - 1][1]);
    cout << Mint(2).pow(p.fi) - 1 + p.se << endl;
    return 0;
}