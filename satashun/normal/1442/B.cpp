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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        V<int> a(n), b(k), pos(n);
        rep(i, n) {
            cin >> a[i], --a[i];
            pos[a[i]] = i;
        }
        rep(i, k) cin >> b[i], --b[i];

        set<int> st;
        for (int x : b) st.insert(x);

        set<int> alive;
        rep(i, n) alive.insert(i);

        Mint ans = 1;

        for (int x : b) {
            int p = pos[x];
            st.erase(x);
            auto it = alive.find(p);
            auto er = it;
            int ok = 0;
            if (next(it) != alive.end() && !st.count(a[*next(it)])) {
                ok++;
                er = next(it);
            }
            if (it != alive.begin() && !st.count(a[*prev(it)])) {
                ok++;
                er = prev(it);
            }
            ans *= ok;
            if (ok == 0) break;
            alive.erase(er);
        }
        cout << ans << '\n';
    }

    return 0;
}