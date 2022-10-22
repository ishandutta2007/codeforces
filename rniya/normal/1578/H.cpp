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
#include <vector>

namespace set_function {

// subset sum : f(S) <- \sum_{T \subseteq S} f(T)
template <typename T> void subset_zeta_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] += f[j];
            }
        }
    }
}

// inverse of subset sum
// g = FZT(f) \iff f = FMT(g)
template <typename T> void subset_mobius_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] -= f[j];
            }
        }
    }
}

// superset sum : f(S) <- \sum_{T \supseteq S} f(T)
template <typename T> void superset_zeta_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] += f[j | i];
            }
        }
    }
}

// inverse of superset sum
// g = FZT(f) \iff f = FMT(g)
template <typename T> void superset_mobius_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] -= f[j | i];
            }
        }
    }
}

template <typename T> void walsh_hadamard_transform(std::vector<T>& f, bool inv = false) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
            }
        }
    }
    if (inv) {
        if (std::is_integral<T>::value) {
            for (auto& x : f) x /= n;
        } else {
            T inv_n = T(1) / f.size();
            for (auto& x : f) x *= inv_n;
        }
    }
}

template <typename T> std::vector<T> and_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    superset_zeta_transform(f);
    superset_zeta_transform(g);
    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];
    superset_mobius_transform(f);
    return f;
}

template <typename T> std::vector<T> or_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    subset_zeta_transform(f);
    subset_zeta_transform(g);
    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];
    subset_mobius_transform(f);
    return f;
}

template <typename T> std::vector<T> xor_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    walsh_hadamard_transform(f);
    walsh_hadamard_transform(g);
    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];
    walsh_hadamard_transform(f, true);
    return f;
}

}  // namespace set_function

/**
 * @brief set function (FZT, FMT, FWHT)
 * @docs docs/convolution/set_function.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> group(n);
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for (; s--;) {
            int x;
            cin >> x;
            group[--x] = i;
        }
    }

    vector<int> cnt(m, 0);
    int cur = (1 << m) - 1;
    auto add = [&](int x) {
        if (cnt[x]++ == 0) cur ^= 1 << x;
    };
    auto del = [&](int x) {
        if (--cnt[x] == 0) cur ^= 1 << x;
    };
    for (int i = 0; i < d; i++) add(group[i]);
    vector<int> f(1 << m, 0);
    for (int l = 0, r = d;; l++, r++) {
        f[cur]++;
        del(group[l]);
        if (r >= n) break;
        add(group[r]);
    }

    set_function::superset_zeta_transform(f);
    int ans = m;
    for (int mask = 0; mask < (1 << m); mask++) {
        if (f[mask] == 0) {
            ans = min(ans, popcount(mask));
        }
    }

    cout << ans << '\n';
    return 0;
}