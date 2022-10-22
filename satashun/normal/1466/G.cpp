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
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<1000000007>;

// from ei1333 library

struct RollingHash {
    static const uint64_t mod = (1ull << 61ull) - 1;
    using uint128_t = __uint128_t;
    vector<uint64_t> power;
    const uint64_t base;

    static inline uint64_t add(uint64_t a, uint64_t b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline uint64_t mul(uint64_t a, uint64_t b) {
        uint128_t c = (uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    static inline uint64_t generate_base() {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<uint64_t> rand(1000, RollingHash::mod - 1);
        return rand(mt);
    }

    inline void expand(size_t sz) {
        if (power.size() < sz + 1) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for (int i = pre_sz - 1; i < sz; i++) {
                power[i + 1] = mul(power[i], base);
            }
        }
    }

    explicit RollingHash(uint64_t base = generate_base())
        : base(base), power{1} {}

    vector<uint64_t> build(const string& s) const {
        int sz = s.size();
        vector<uint64_t> hashed(sz + 1);
        for (int i = 0; i < sz; i++) {
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
        return hashed;
    }

    template <typename T>
    vector<uint64_t> build(const vector<T>& s) const {
        int sz = s.size();
        vector<uint64_t> hashed(sz + 1);
        for (int i = 0; i < sz; i++) {
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
        return hashed;
    }

    uint64_t query(const vector<uint64_t>& s, int l, int r) {
        expand(r - l);
        return add(s[r], mod - mul(s[l], power[r - l]));
    }

    uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
        expand(h2len);
        return add(mul(h1, power[h2len]), h2);
    }

    uint64_t calc_hash(const string& s) const {
        int sz = s.size();
        uint64_t res = 0;
        for (int i = 0; i < sz; i++) {
            res = add(mul(res, base), s[i]);
        }
        return res;
    }

    int lcp(const vector<uint64_t>& a, int l1, int r1,
            const vector<uint64_t>& b, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};

const int MX = TEN(6) * 2 + 10;

Mint p2[MX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    p2[0] = 1;
    rep(i, MX - 1) p2[i + 1] = p2[i] * 2;

    int n, q;
    string s0, t;
    cin >> n >> q >> s0 >> t;
    V<string> s{s0};

    int now = 0;

    while (now < n && s.back().size() < MX) {
        auto ts = s.back();
        s.pb(ts + t[now] + ts);
        now++;
    }

    V<Mint> ans(q);
    V<string> w(q);

    VV<uint64_t> hs;
    RollingHash rh;

    for (int i = 0; i <= now; ++i) {
        hs.pb(rh.build(s[i]));
    }

    V<pii> upd;

    rep(i, q) {
        int k;
        cin >> k >> w[i];

        int p = min(now, k);
        Mint res = 0;
        int wl = SZ(w[i]);
        auto x = rh.calc_hash(w[i]);

        for (int j = 0; j <= p; ++j) {
            Mint inc;

            if (j == 0) {
                for (int k = 0; k <= SZ(s[0]) - wl; ++k) {
                    auto y = rh.query(hs[j], k, k + wl);
                    if (y == x) inc++;
                }
            } else {
                int len = SZ(s[j - 1]);
                for (int k = max(0, len - wl + 1);
                     k <= min(len, len * 2 + 1 - wl); ++k) {
                    auto y = rh.query(hs[j], k, k + wl);
                    if (y == x) inc++;
                }
            }
            res = res * 2 + inc;
        }

        debug(i, p, res);
        // now, res = c(p)
        ans[i] = res * p2[k - p];
        if (k > now) {
            upd.eb(k, i);
        }
    }

    sort(ALL(upd));

    int piv = 0;
    V<Mint> coef(26);

    for (int k = now + 1; k <= n; ++k) {
        {
            int c = t[k - 1] - 'a';
            rep(a, 26) coef[a] *= 2;
            coef[c]++;
        }

        while (piv < SZ(upd) && upd[piv].fi == k) {
            int id = upd[piv].se;
            int len = SZ(s[now]) / 2;
            int wl = SZ(w[id]);
            array<Mint, 26> inc;
            auto vh = rh.build(w[id]);

            for (int l = max(0, len - wl + 1); l <= min(len, len * 2 + 1 - wl);
                 ++l) {
                int m = len - l;
                auto xl = rh.query(vh, 0, m);
                auto xr = rh.query(vh, m + 1, wl);
                int c = w[id][m] - 'a';
                auto yl = rh.query(hs[now], l, len);
                auto yr = rh.query(hs[now], len + 1, wl + l);
                if (xl == yl && xr == yr) inc[c]++;
            }
            rep(c, 26) ans[id] += inc[c] * coef[c];
            piv++;
        }
    }

    rep(i, q) cout << ans[i] << '\n';

    return 0;
}