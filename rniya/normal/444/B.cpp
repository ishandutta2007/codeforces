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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX = 1024;
int n, d;
ll x;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

pair<vector<int>, vector<int>> initAB() {
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < n; i++) swap(a[i], a[getNextX() % (i + 1)]);
    for (int i = 0; i < n; i++) b[i] = (i < d);
    for (int i = 0; i < n; i++) swap(b[i], b[getNextX() % (i + 1)]);
    return {a, b};
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> d >> x;
    auto tmp = initAB();
    vector<int> a = tmp.first, b = tmp.second;
    vector<int> one, pos(n + 1);
    for (int i = 0; i < n; i++) {
        if (b[i]) one.emplace_back(i);
        pos[a[i]] = i;
    }

    vector<int> c(n, 0);
    for (int i = n, _ = 0; i > 0 && _ < MAX; i--, _++) {
        for (int& j : one) {
            if (pos[i] + j < n && !c[pos[i] + j]) {
                c[pos[i] + j] = i;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        if (c[k]) continue;
        for (int& j : one) {
            if (k - j >= 0) {
                c[k] = max(c[k], a[k - j]);
            }
        }
    }

    for (int& x : c) cout << x << '\n';
    return 0;
}