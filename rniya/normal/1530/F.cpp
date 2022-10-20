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

vector<int> gray_code(int n) {
    vector<int> ret(1 << n);
    for (int i = 0; i < (int)ret.size(); i++) ret[i] = i ^ (i >> 1);
    return ret;
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 31607;
// const long long MOD = 998244353;

using mint = modint<MOD>;

mint small(int n, vector<vector<mint>> a) {
    mint ans = 0;
    for (int mask = 0; mask < (1 << (2 * n + 2)); mask++) {
        vector<vector<bool>> used(n, vector<bool>(n, false));
        mint prod = 1;
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;
            for (int j = 0; j < n; j++) {
                if (used[i][j]) continue;
                used[i][j] = true;
                prod *= a[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (!(mask >> (n + j) & 1)) continue;
            for (int i = 0; i < n; i++) {
                if (used[i][j]) continue;
                used[i][j] = true;
                prod *= a[i][j];
            }
        }
        if (mask >> (2 * n) & 1) {
            for (int i = 0; i < n; i++) {
                if (used[i][i]) continue;
                used[i][i] = true;
                prod *= a[i][i];
            }
        }
        if (mask >> (2 * n + 1) & 1) {
            for (int i = 0; i < n; i++) {
                if (used[i][n - 1 - i]) continue;
                used[i][n - 1 - i] = true;
                prod *= a[i][n - 1 - i];
            }
        }
        int flag = __builtin_popcount(mask);
        if (flag & 1)
            ans += prod;
        else
            ans -= prod;
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<mint>> a(n, vector<mint>(n));
    mint inv10000 = mint(1) / 10000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a[i][j] = inv10000 * x;
        }
    }
    // debug(small(n, a));

    vector<vector<mint>> b(n, vector<mint>(n));
    vector<mint> col(n, 1), row(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = mint(1) / a[i][j];
            row[i] *= a[i][j];
            col[j] *= a[i][j];
        }
    }

    vector<mint> dp(2), ndp(2);
    auto calc = [&](int mask) -> mint {
        int flag = 0;
        mint sum = 0, nprod = 1;
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;
            flag ^= 1;
            nprod *= row[i];
        }

        for (int k = 0; k < 4; k++) {
            mint prod = nprod;
            int nflag = flag;
            if (k & 1) {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) continue;
                    prod *= a[i][i];
                    col[i] *= b[i][i];
                }
                nflag ^= 1;
            }
            if (k & 2) {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) continue;
                    if (i == n - 1 - i && (k & 1)) continue;
                    prod *= a[i][n - 1 - i];
                    col[n - 1 - i] *= b[i][n - 1 - i];
                }
                nflag ^= 1;
            }

            for (int i = 0; i < 2; i++) dp[i] = ndp[i] = 0;
            dp[nflag] = prod;

            for (int j = 0; j < n; j++) {
                for (int i = 0; i < 2; i++) {
                    ndp[i ^ 1] += dp[i] * col[j];
                    ndp[i] += dp[i];
                    dp[i] = 0;
                }
                swap(dp, ndp);
            }
            sum -= dp[0];
            sum += dp[1];

            if (k & 1) {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) continue;
                    col[i] *= a[i][i];
                }
            }
            if (k & 2) {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) continue;
                    if (i == n - 1 - i && (k & 1)) continue;
                    col[n - 1 - i] *= a[i][n - 1 - i];
                }
            }
        }
        return sum;
    };

    vector<int> gray = gray_code(n);
    int pre = -1;
    mint ans = 0;
    for (int& mask : gray) {
        if (~pre) {
            int XOR = mask ^ pre;
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (XOR >> i & 1) {
                    x = i;
                    break;
                }
            }
            if (mask > pre) {
                for (int j = 0; j < n; j++) {
                    col[j] *= b[x][j];
                }
            } else {
                for (int j = 0; j < n; j++) {
                    col[j] *= a[x][j];
                }
            }
        }

        ans += calc(mask);
        pre = mask;
    }

    cout << ans + 1 << '\n';
    return 0;
}