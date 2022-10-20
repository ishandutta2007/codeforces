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
 * @brief  modint
 * @docs docs/modulo/modint.md
 */
class dynamic_modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    static u32& mod() {
        static u32 mod_ = 0;
        return mod_;
    }

public:
    u32 v;
    static void set_mod(const u32 x) {
        assert(x < (u32(1) << 31));
        mod() = x;
    }
    static u32 get_mod() { return mod(); }
    dynamic_modint(const i64 x = 0) : v(x < 0 ? get_mod() - 1 - (-(x + 1) % get_mod()) : x % get_mod()) {}
    u32& value() noexcept { return v; }
    const u32& value() const noexcept { return v; }
    dynamic_modint operator+(const dynamic_modint& rhs) const { return dynamic_modint(*this) += rhs; }
    dynamic_modint operator-(const dynamic_modint& rhs) const { return dynamic_modint(*this) -= rhs; }
    dynamic_modint operator*(const dynamic_modint& rhs) const { return dynamic_modint(*this) *= rhs; }
    dynamic_modint operator/(const dynamic_modint& rhs) const { return dynamic_modint(*this) /= rhs; }
    dynamic_modint& operator+=(const dynamic_modint& rhs) {
        v += rhs.v;
        if (v >= get_mod()) v -= get_mod();
        return *this;
    }
    dynamic_modint& operator-=(const dynamic_modint& rhs) {
        if (v < rhs.v) v += get_mod();
        v -= rhs.v;
        return *this;
    }
    dynamic_modint& operator*=(const dynamic_modint& rhs) {
        v = (u64)v * rhs.v % get_mod();
        return *this;
    }
    dynamic_modint& operator/=(const dynamic_modint& rhs) { return *this *= rhs.pow(get_mod() - 2); }
    dynamic_modint pow(u64 exp) const {
        dynamic_modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    dynamic_modint& operator++() {
        if (++v == get_mod()) v = 0;
        return *this;
    }
    dynamic_modint& operator--() {
        if (v == 0) v = get_mod();
        return --v, *this;
    }
    dynamic_modint operator++(int) {
        dynamic_modint t = *this;
        return ++*this, t;
    }
    dynamic_modint operator--(int) {
        dynamic_modint t = *this;
        return --*this, t;
    }
    dynamic_modint operator-() { return dynamic_modint(get_mod() - v); }
    template <class T> friend dynamic_modint operator+(T x, dynamic_modint y) { return dynamic_modint(x) + y; }
    template <class T> friend dynamic_modint operator-(T x, dynamic_modint y) { return dynamic_modint(x) - y; }
    template <class T> friend dynamic_modint operator*(T x, dynamic_modint y) { return dynamic_modint(x) * y; }
    template <class T> friend dynamic_modint operator/(T x, dynamic_modint y) { return dynamic_modint(x) / y; }
    bool operator==(const dynamic_modint& rhs) { return v == rhs.v; }
    bool operator!=(const dynamic_modint& rhs) { return v != rhs.v; }
    bool operator!() { return !v; }
    friend istream& operator>>(istream& s, dynamic_modint& rhs) {
        i64 v;
        rhs = dynamic_modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const dynamic_modint& rhs) { return s << rhs.v; }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using mint = dynamic_modint;
const int MAX = 505, MAX_INV = MAX * MAX, HALF = MAX_INV / 2;
mint dp[2][MAX_INV][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, mod;
    cin >> n >> mod;
    mint::set_mod(mod);

    vector<mint> P(n + 1, 1);
    for (int i = 1, j = n; i <= n; i++, j--) P[i] = P[i - 1] * j;
    int cur = 0;
    dp[0][HALF][2] = 1;
    mint ans = 0;

    for (int i = 0; i < n; i++, cur ^= 1) {
        for (int j = 0; j < MAX_INV; j++) {
            for (int k = 0; k < 3; k++) {
                mint x = dp[cur][j][k];
                if (x == 0) continue;
                int nxt = cur ^ 1;
                for (int l = 0; l <= i; l++) {
                    for (int m = 0; m <= i; m++) {
                        int nj = j + l - m, nk = (l == 0 && m == 0 ? 2 : (l == 0 ? 0 : (m == 0 ? 1 : k)));
                        dp[nxt][nj][nk] += x;
                    }
                }
                dp[cur][j][k] = 0;
            }
        }
        mint sum = 0;
        for (int j = HALF + 1; j < MAX_INV; j++) sum += dp[cur ^ 1][j][0];
        ans += P[n - 1 - i] * sum;
    }

    cout << ans << '\n';
    return 0;
}