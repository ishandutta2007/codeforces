// #define LOCAL
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
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
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
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    return os;
}
template <typename T, size_t N> ostream& operator<<(ostream& os, const array<T, N>& v) {
    for (size_t i = 0; i < N; i++) {
        os << v[i] << (i + 1 == N ? "" : " ");
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
#define debug(...) void(0)
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
long long MSK(int n) { return (1LL << n) - 1; }

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

template <typename T> void mkuni(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
template <typename T> int lwb(const vector<T>& v, const T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
#pragma endregion

#include <numeric>
#include <vector>

namespace elementary_math {

template <typename T> std::vector<T> divisor(T n) {
    std::vector<T> res;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    return res;
}

template <typename T> std::vector<std::pair<T, int>> prime_factor(T n) {
    std::vector<std::pair<T, int>> res;
    for (T p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            res.emplace_back(p, 0);
            while (n % p == 0) {
                res.back().second++;
                n /= p;
            }
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}

std::vector<int> osa_k(int n) {
    std::vector<int> min_factor(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (min_factor[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!min_factor[j]) {
                min_factor[j] = i;
            }
        }
    }
    return min_factor;
}

std::vector<int> prime_factor(const std::vector<int>& min_factor, int n) {
    std::vector<int> res;
    while (n > 1) {
        res.emplace_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

long long modpow(long long x, long long n, long long mod) {
    assert(0 <= n && 1 <= mod && mod < (1LL << 31));
    if (mod == 1) return 0;
    x %= mod;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else
        x = 1, y = 0;
    return d;
}

long long inv_mod(long long a, long long mod) {
    assert(1 <= mod);
    long long x, y;
    if (extgcd(a, mod, x, y) != 1) return -1;
    return (mod + x % mod) % mod;
}

template <typename T> T euler_phi(T n) {
    auto pf = prime_factor(n);
    T res = n;
    for (const auto& p : pf) {
        res /= p.first;
        res *= p.first - 1;
    }
    return res;
}

std::vector<int> euler_phi_table(int n) {
    std::vector<int> res(n + 1, 0);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (res[i] != i) continue;
        for (int j = i; j <= n; j += i) res[j] = res[j] / i * (i - 1);
    }
    return res;
}

// minimum i > 0 s.t. x^i \equiv 1 \pmod{m}
template <typename T> T order(T x, T m) {
    T n = euler_phi(m);
    auto cand = divisor(n);
    sort(cand.begin(), cand.end());
    for (auto& i : cand) {
        if (modpow(x, i, m) == 1) {
            return i;
        }
    }
    return -1;
}

}  // namespace elementary_math

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<int> c(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
        sum += b[i];
    }
    sort(c.rbegin(), c.rend());
    vector<ll> Max(n + 1);  // i  red 
    Max[0] = sum;
    int neg = n + 1;  // neg 
    for (int i = 0; i < n; i++) {
        sum += c[i];
        if (neg == n + 1 and c[i] < 0) neg = i + 1;
        Max[i + 1] = sum;
    }
    debug(Max);

    auto query = [&](ll x, ll y) -> ll {
        debug(x, y);
        ll p = 0, q = 0;
        ll g = elementary_math::extgcd(x, y, p, q);
        if (n % g != 0) return -1;
        p *= n / g;
        q *= n / g;
        ll l = x * y / g;
        ll r = l / x, s = l / y;
        if (p >= 0) {
            ll need = ceil(-p, r);
            p += r * need;
            q -= s * need;
        } else {
            ll need = floor(p, r);
            p -= r * need;
            q += s * need;
        }
        debug(p, q);
        if (q < 0) return -1;
        ll L = p * x, R = (p + r * (q / s)) * x;
        debug(L, R, neg);
        if (neg <= L) return Max[L];
        ll tmp = L + (neg - 1 - L) / (r * x) * (r * x);
        return max(Max[min(R, tmp)], Max[min(R, tmp + r * x)]);
    };

    int m;
    cin >> m;
    for (; m--;) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << '\n';
    }
    return 0;
}