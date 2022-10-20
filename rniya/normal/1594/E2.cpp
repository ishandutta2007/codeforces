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

#include <cassert>
#include <cstdint>
#include <iostream>

template <uint64_t Modulus> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static_assert(Modulus < static_cast<uint32_t>(1) << 31, "Modulus must be less than 2**31");
    static constexpr u32 mod = Modulus;
    u32 v;

public:
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& val() noexcept { return v; }
    constexpr const u32& val() const noexcept { return v; }
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
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.inv(); }
    constexpr modint pow(long long n) const noexcept {
        assert(0 <= n);
        modint self(*this), res(1);
        while (n > 0) {
            if (n & 1) res *= self;
            self *= self;
            n >>= 1;
        }
        return res;
    }
    constexpr modint inv() const noexcept {
        assert(*this != 0);
        return pow(mod - 2);
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
    friend std::istream& operator>>(std::istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief modint
 * @docs docs/modulo/modint.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using mint = modint<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    int n;
    cin >> n;
    auto ctoi = [](string c) {
        if (c == "white") return 0;
        if (c == "yellow") return 5;
        if (c == "green") return 1;
        if (c == "blue") return 4;
        if (c == "red") return 2;
        return 3;
    };
    vector<ll> v(n);
    vector<int> c(n);
    set<ll> path;
    map<ll, int> must;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> v[i] >> s;
        c[i] = ctoi(s);
        must[v[i]] = c[i];
        ll x = v[i];
        for (; x > 0; x >>= 1) path.emplace(x);
    }

    vector<vector<ll>> cand(k);
    for (auto& x : path) cand[topbit(x)].emplace_back(x);
    vector<mint> dp(k, 0);
    dp[0] = 1;
    for (int i = 1; i < k; i++) dp[i] = dp[i - 1] * 4 * dp[i - 1] * 4;
    map<ll, vector<mint>> mp;
    for (int i = 0; i < n; i++) {
        if (topbit(v[i]) == k - 1) {
            vector<mint> a(6, 0);
            a[c[i]]++;
            mp[v[i]] = a;
        }
    }
    for (int i = k - 2; i >= 0; i--) {
        for (auto& x : cand[i]) {
            vector<mint> sum(6, 0), left, right;
            if (mp.count(x << 1 | 0))
                left = mp[x << 1 | 0];
            else
                for (int j = 0; j < 6; j++) left.emplace_back(dp[k - 2 - i]);
            if (mp.count(x << 1 | 1))
                right = mp[x << 1 | 1];
            else
                for (int j = 0; j < 6; j++) right.emplace_back(dp[k - 2 - i]);
            mint lsum = accumulate(ALL(left), mint(0)), rsum = accumulate(ALL(right), mint(0));
            for (int j = 0; j < 6; j++) sum[j] = (lsum - left[j] - left[5 - j]) * (rsum - right[j] - right[5 - j]);
            if (must.count(x)) {
                int ok = must[x];
                for (int j = 0; j < 6; j++) {
                    if (j != ok) {
                        sum[j] = 0;
                    }
                }
            }
            mp[x] = sum;
        }
    }

    assert(mp.count(1));
    auto res = mp[1];
    mint ans = accumulate(ALL(res), mint(0));
    cout << ans << '\n';
    return 0;
}