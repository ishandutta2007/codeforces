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

#include <cassert>
#include <vector>

struct CentroidDecomposition {
    std::vector<std::vector<int>> G;

    CentroidDecomposition(int n) : G(n), n(n), sub(n), is_centroid(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    std::vector<int> build(int x = 0) {
        centroids.clear();
        fill(is_centroid.begin(), is_centroid.end(), false);
        centroid_decomposition(x);
        return centroids;
    }

private:
    int n;
    std::vector<int> sub, centroids;
    std::vector<bool> is_centroid;

    int dfs_sz(int v, int p) {
        sub[v] = 1;
        for (int& u : G[v]) {
            if (u == p || is_centroid[u]) continue;
            sub[v] += dfs_sz(u, v);
        }
        return sub[v];
    }

    int dfs_search_centroid(int v, int p, int mid) {
        for (int& u : G[v]) {
            if (u == p || is_centroid[u]) continue;
            if (sub[u] > mid) return dfs_search_centroid(u, v, mid);
        }
        return v;
    }

    void centroid_decomposition(int r) {
        int centroid = dfs_search_centroid(r, -1, dfs_sz(r, -1) / 2);
        centroids.emplace_back(centroid);
        is_centroid[centroid] = true;
        for (int& ch : G[centroid]) {
            if (is_centroid[ch]) continue;
            centroid_decomposition(ch);
        }
    }
};

/**
 * @brief Centroid Decomposition
 * @docs docs/tree/CentroidDecomposition.md
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    CentroidDecomposition CD(n);
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        CD.add_edge(--u, --v);
        G[u].emplace_back(v, t);
        G[v].emplace_back(u, t);
    }

    auto roots = CD.build();
    vector<bool> alive(n, true);

    auto dfs = [&](auto self, int v, int p, int pre, int dep, mint sum, vector<pair<int, mint>>& path) -> void {
        sum += a[v];
        path.emplace_back(dep, sum);
        for (auto& e : G[v]) {
            int u = e.first;
            if (u == p || !alive[u]) continue;
            self(self, u, v, e.second, dep + (pre != e.second), sum, path);
        }
    };

    auto solve = [&](int r) -> mint {
        alive[r] = false;
        mint res = 0;
        vector<vector<mint>> cnt_rui(2, vector<mint>(1, 0)),  //  i  j 
            sum_rui(2, vector<mint>(1, 0));  //  i  j 
        for (auto& e : G[r]) {
            int ch = e.first, col = e.second;
            if (!alive[ch]) continue;
            vector<pair<int, mint>> path;
            dfs(dfs, ch, r, col, 0, 0, path);
            int Max = cnt_rui[col].size() - 1;
            for (auto& p : path) {
                int dep = p.first;
                mint sum = p.second;
                Max = max(Max, dep);
                if (dep <= k) res += a[r] + sum;  // 
                for (int i = 0; i < 2; i++) {
                    int lim = min((int)cnt_rui[i].size() - 1, k - dep - (i != col));
                    if (lim >= 0) res += cnt_rui[i][lim] * sum + sum_rui[i][lim];  // 
                }
            }
            // debug(r, ch, path, res);
            vector<mint> cnt_imos(Max + 1, 0), sum_imos(Max + 1, 0);
            for (auto& p : path) {
                int dep = p.first;
                mint sum = p.second;
                cnt_imos[dep]++;
                sum_imos[dep] += sum + a[r];
            }
            for (int i = 0; i < Max; i++) cnt_imos[i + 1] += cnt_imos[i], sum_imos[i + 1] += sum_imos[i];
            while ((int)cnt_rui[col].size() <= Max) cnt_rui[col].emplace_back(cnt_rui[col].back());
            while ((int)sum_rui[col].size() <= Max) sum_rui[col].emplace_back(sum_rui[col].back());
            for (int i = 0; i <= Max; i++) cnt_rui[col][i] += cnt_imos[i], sum_rui[col][i] += sum_imos[i];
            // debug(r, ch, col, cnt_imos, sum_imos, cnt_rui[col], sum_rui[col]);
        }
        res += a[r];  // 
        // debug(r, res);
        return res;
    };

    mint ans = 0;
    for (auto& r : roots) ans += solve(r);
    cout << ans << '\n';
    return 0;
}