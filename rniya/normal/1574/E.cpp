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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
// const long long MOD = 1000000007;
const long long MOD = 998244353;

using mint = modint<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;

    int Max = max(n, m);
    vector<mint> power(Max + 1, 1);
    for (int i = 0; i < Max; i++) power[i + 1] = power[i] * 2;

    map<pair<int, int>, int> mp;
    // 0 : 0  0101...  0  0101... a_{i, j} = ((i ^ j) & 1)
    // 1 : 0  1010...  0  1010... a_{i, j} = ((i ^ j ^ 1) & 1)
    vector<int> error(2, 0);
    // 0 : 0  0101...
    // 1 : 0  1010...
    // 2 : 0  0101...
    // 3 : 0  1010...
    vector<int> base_error(4, 0);
    vector<vector<int>> data(4, vector<int>(Max));
    vector<vector<vector<int>>> determined(
        4, vector<vector<int>>(
               Max, vector<int>(2, 0)));  //  j  k 
    vector<int> still(4);
    for (int i = 0; i < 4; i++) {
        still[i] = (i < 2 ? n - 1 : m - 1);
        for (int j = 0; j < Max; j++) {
            data[i][j] = (!(i & 1) ? j & 1 : (j ^ 1) & 1);
        }
    }

    auto unchange = [&](int x, int y) {
        if (!mp.count({x, y}) || mp[{x, y}] == -1) return;
        int val = mp[{x, y}];
        if (x == 0) {
            base_error[0] -= (val != (y & 1));
            base_error[1] -= (val == (y & 1));
        } else {
            for (int i = 0; i < 2; i++) {
                int j = x, k = data[i][0] ^ data[i][x ^ y ^ j] ^ val;
                determined[i][j][k]--;
                if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] == 0)
                    still[i]++;
                else if (determined[i][j][k] == 0)
                    base_error[i]--;
            }
        }
        if (y == 0) {
            base_error[2] -= (val != (x & 1));
            base_error[3] -= (val == (x & 1));
        } else {
            for (int i = 2; i < 4; i++) {
                int j = y, k = data[i][0] ^ data[i][x ^ y ^ j] ^ val;
                determined[i][j][k]--;
                if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] == 0)
                    still[i]++;
                else if (determined[i][j][k] == 0)
                    base_error[i]--;
            }
        }
        error[0] -= (val != ((x ^ y) & 1));
        error[1] -= (val == ((x ^ y) & 1));
        mp[{x, y}] = -1;
    };
    auto change = [&](int x, int y, int val) {
        if (x == 0) {
            base_error[0] += (val != (y & 1));
            base_error[1] += (val == (y & 1));
        } else {
            for (int i = 0; i < 2; i++) {
                int j = x, k = data[i][0] ^ data[i][x ^ y ^ j] ^ val;
                if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] == 0)
                    still[i]--;
                else if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] > 0)
                    base_error[i]++;
                determined[i][j][k]++;
            }
        }
        if (y == 0) {
            base_error[2] += (val != (x & 1));
            base_error[3] += (val == (x & 1));
        } else {
            for (int i = 2; i < 4; i++) {
                int j = y, k = data[i][0] ^ data[i][x ^ y ^ j] ^ val;
                if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] == 0)
                    still[i]--;
                else if (determined[i][j][k] == 0 && determined[i][j][k ^ 1] > 0)
                    base_error[i]++;
                determined[i][j][k]++;
            }
        }
        error[0] += (val != ((x ^ y) & 1));
        error[1] += (val == ((x ^ y) & 1));
        mp[{x, y}] = val;
    };
    auto query = [&](int x, int y, int t) {
        unchange(x, y);
        if (~t) change(x, y, t);
        mint res = 0;
        for (int i = 0; i < 4; i++) {
            assert(base_error[i] >= 0);
            if (base_error[i] != 0) continue;
            res += power[still[i]];
        }
        for (int i = 0; i < 2; i++) {
            assert(error[i] >= 0);
            res -= (error[i] == 0);
        }

        return res;
    };

    for (; k--;) {
        int x, y, t;
        cin >> x >> y >> t;
        cout << query(--x, --y, t) << '\n';
    }
    return 0;
}