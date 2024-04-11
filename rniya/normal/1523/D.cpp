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
 * @brief (32bit)
 * @docs docs/util/RandomNumberGenerator.md
 */
struct RandomNumberGenerator {
    mt19937 mt;
    RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    uint32_t operator()(uint32_t a, uint32_t b) {
        uniform_int_distribution<uint32_t> dist(a, b - 1);
        return dist(mt);
    }
    uint32_t operator()(uint32_t b) { return (*this)(0, b); }
};

/**
 * @brief ()
 * @docs docs/convolution/FastZetaMobiusTransform.md
 */
template <typename T> void FastZetaTransform(int n, vector<T>& f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (!((j >> i) & 1)) {
                f[j] += f[j ^ (1 << i)];
            }
        }
    }
}

template <typename T> void FastMobiusTransform(int n, vector<T>& f) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (!((j >> i) & 1)) {
                f[j] -= f[j ^ (1 << i)];
            }
        }
    }
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int ITER = 50;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> S(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            S[i][j] = c - '0';
        }
    }

    RandomNumberGenerator rng;
    auto calc = [&](int x) -> pair<int, string> {
        vector<int> cand;
        for (int j = 0; j < m; j++) {
            if (S[x][j]) {
                cand.emplace_back(j);
            }
        }

        int sz = cand.size();
        vector<int> cnt(1 << sz, 0);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < sz; j++) mask |= S[i][cand[j]] << j;
            cnt[mask]++;
        }

        FastZetaTransform(sz, cnt);
        int res = 0, arg;
        for (int mask = 0; mask < (1 << sz); mask++) {
            int flag = __builtin_popcount(mask);
            if (cnt[mask] * 2 >= n && res < flag) {
                res = max(res, flag);
                arg = mask;
            }
        }
        string T(m, '0');
        for (int i = 0; i < sz; i++) {
            if (arg >> i & 1) {
                T[cand[i]] = '1';
            }
        }
        return {res, T};
    };

    int Max = 0;
    string ans(m, '0');
    for (int i = 0; i < ITER; i++) {
        int x = (n > ITER ? rng(n) : i % n);
        auto p = calc(x);
        if (Max < p.first) {
            Max = p.first;
            ans = p.second;
        }
    }

    cout << ans << '\n';
    return 0;
}