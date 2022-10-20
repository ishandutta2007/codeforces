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
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
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
 * @brief Z-Algorithm
 * @docs docs/string/Z_Algorithm.md
 */
template <typename T> vector<int> Z_Algorithm(const T& s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 0; i < n;) {
        while (i + j < n && s[j] == s[i + j]) j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + z[k] < j) z[i + k] = z[k], k++;
        i += k;
        j -= k;
    }
    return z;
}

template <typename T> vector<int> LCP(const T& s, const T& t) {
    T u(s);
    u.insert(u.begin(), t.begin(), t.end());
    vector<int> z = Z_Algorithm(u);
    for (int& i : z) i = min(i, (int)t.size());
    return vector<int>(z.begin() + t.size(), z.end());
}

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
    string S;
    cin >> S;

    int n = S.size();
    vector<vector<int>> Z(n);
    for (int i = 0; i < n; i++) {
        string T = S.substr(i, n - i);
        Z[i] = LCP(S, T);
    }

    auto comp = [&](int i, int j) {  // S[i,j)(0)S[j,j+(j-i))(1)
        if (j == 0) return false;
        int lcp = min(Z[i][j], j - i);
        if (lcp == j - i) return true;
        if (j + lcp >= n) return true;
        return Z[j + lcp] > Z[i + lcp];
    };

    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
    vector<vector<int>> ndp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 1;
    ndp[0][0] = 0;

    for (int j = 0; j <= n; j++) {
        for (int i = 0; i < (j == 0 ? 1 : j); i++) {
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
                chmin(ndp[i][j], ndp[i][j - 1]);
            }
            if (j == n) continue;
            if (S[j] == '0') continue;
            if (j + (j - i) > n) continue;
            int nxt = j + (j - i) + 1 - comp(i, j);
            if (nxt > n) continue;
            // debug(i, j, nxt, comp(i, j));
            dp[j][nxt] += dp[i][j];
            chmin(ndp[j][nxt], ndp[i][j] + 1);
        }
        if (j == 0) {
            dp[0][0] = 0;
            ndp[0][0] = INF;
        }
    }

    mint ans = 0;
    int Min = INF;
    mint res = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += dp[i][n];
        if (ndp[i][n] < INF) {
            if (n - i < 20) {
                int calc = 0;
                for (int j = i; j < n; j++) calc = calc * 2 + (S[j] - '0');
                chmin(Min, calc + ndp[i][n]);
            } else {
                if (Min < INF) continue;
                if (Min < 0) continue;
                Min = -1;
                for (int j = i; j < n; j++) res = res * 2 + (S[j] - '0');
                res += ndp[i][n];
            }
        }
    }

    cout << ans << '\n';
    if (Min >= 0)
        cout << Min << '\n';
    else
        cout << res << '\n';
    return 0;
}