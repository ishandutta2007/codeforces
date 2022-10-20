#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

/**
 * @brief modint
 * @docs docs/modulo/modint.md
 */
template <uint32_t mod> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

public:
    u32 v;
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& value() noexcept { return v; }
    constexpr const u32& value() const noexcept { return v; }
    constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint& rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint& rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint& rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr modint& operator+=(const modint& rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr modint& operator-=(const modint& rhs) noexcept {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    constexpr modint& operator*=(const modint& rhs) noexcept {
        v = (u64)v * rhs.v % mod;
        return *this;
    }
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    constexpr modint& operator++() noexcept {
        if (++v == mod) v = 0;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        if (v == 0) v = mod;
        return --v, *this;
    }
    constexpr modint operator++(int) noexcept {
        modint t = *this;
        return ++*this, t;
    }
    constexpr modint operator--(int) noexcept {
        modint t = *this;
        return --*this, t;
    }
    constexpr modint operator-() const noexcept { return modint(mod - v); }
    template <class T> friend constexpr modint operator+(T x, modint y) noexcept { return modint(x) + y; }
    template <class T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }
    template <class T> friend constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }
    template <class T> friend constexpr modint operator/(T x, modint y) noexcept { return modint(x) / y; }
    constexpr bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }
    constexpr bool operator!=(const modint& rhs) const noexcept { return v != rhs.v; }
    constexpr bool operator!() const noexcept { return !v; }
    friend istream& operator>>(istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief combination
 * @docs docs/combinatorics/combination.md
 */
template <class M> struct Combination {
    vector<M> _fac, _inv, _finv;
    Combination(int n) : _fac(n + 1), _inv(n + 1), _finv(n + 1) {
        _fac[0] = _finv[n] = _inv[0] = 1;
        for (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;
        _finv[n] /= _fac[n];
        for (int i = n - 1; i >= 0; i--) _finv[i] = _finv[i + 1] * (i + 1);
        for (int i = 1; i <= n; i++) _inv[i] = _finv[i] * _fac[i - 1];
    }
    M fac(int k) const { return _fac[k]; }
    M finv(int k) const { return _finv[k]; }
    M inv(int k) const { return _inv[k]; }
    M P(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[n - r];
    }
    M C(int n, int r) const {
        if (n < 0 || r < 0 || n < r) return 0;
        return _fac[n] * _finv[r] * _finv[n - r];
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using mint = modint<MOD>;
const int MAX_N = 1000010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(MAX_N);
    int n;
    cin >> n;
    vector<pair<int, int>> seat;
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        if (--idx >= 0) seat.emplace_back(i, idx);
    }

    sort(seat.begin(), seat.end(), [](pair<int, int> p, pair<int, int> q) { return p.second > q.second; });
    int l = 0, r = n - 1, pre = n;
    mint ans = 1;

    for (size_t i = 0; i < seat.size(); i++) {
        int pos = seat[i].first, idx = seat[i].second, add = pre - idx - 1;
        if (pos < l || r < pos) {
            cout << 0 << '\n';
            return 0;
        }
        if (i + 1 == seat.size()) {
            if (idx == 0) {
                int addl = pos - l, addr = add - addl;
                ans *= COM.C(add, addl);
                l += addl + 1;
                r -= addr;
            } else {
                mint sum = 0;
                {  // 
                    int addl = pos - l;
                    sum += COM.C(add, addl);
                }
                {  // 
                    int addr = r - pos, addl = add - addr;
                    sum += COM.C(add, addl);
                    l += addl;
                    r -= addr + 1;
                }
                ans *= sum;
            }
        } else {
            int nxt = seat[i + 1].first;
            if (pos < nxt) {  // 
                int addl = pos - l, addr = add - addl;
                ans *= COM.C(add, addl);
                l += addl + 1;
                r -= addr;
            } else {  // 
                int addr = r - pos, addl = add - addr;
                ans *= COM.C(add, addl);
                l += addl;
                r -= addr + 1;
            }
        }
        pre = idx;
    }

    assert(l - 1 <= r);
    if (r - l >= 0) ans *= mint(2).pow(r - l);
    cout << ans << '\n';
    return 0;
}