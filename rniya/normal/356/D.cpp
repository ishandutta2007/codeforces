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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

#include <vector>

std::vector<bool> SubsetSum(const std::vector<int>& a, int s) {
    int n = a.size();
    std::vector<int> dp(s + 1, -1);
    int m = (s >> 6) + 1;
    std::vector<unsigned long long> A(m, 0), B(m, 0);
    A[0] = 1;

    for (int i = 0; i < n; i++) {
        int x = a[i] >> 6, y = a[i] & 63;
        for (int j = 0; j < m; j++) {
            if (j + x < m) B[j + x] |= (A[j] << y);
            if (j + x + 1 < m and y) B[j + x + 1] |= (A[j] >> (64 - y));
        }
        for (int j = 0; j < m; j++) {
            B[j] &= ~A[j];
            A[j] |= B[j];
            while (B[j]) {
                int k = __builtin_ctzll(B[j]);
                if ((j << 6) + k <= s) dp[(j << 6) + k] = i;
                B[j] &= ~(1ULL << k);
            }
        }
    }

    if (s > 0 and dp[s] == -1) return {};
    std::vector<bool> res(n, false);
    while (s > 0) {
        res[dp[s]] = true;
        s -= a[dp[s]];
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    cin >> a;

    if (n == 1) {
        if (a[0] != s) {
            cout << -1 << '\n';
        } else {
            cout << a[0] << ' ' << 0 << '\n';
        }
        return 0;
    }

    int must = max_element(a.begin(), a.end()) - a.begin();
    if (a[must] > s) {
        cout << -1 << '\n';
        return 0;
    }
    s -= a[must];
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (i != must) {
            b.emplace_back(a[i]);
        }
    }
    auto res = SubsetSum(b, s);
    if (res.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<bool> used(n, false);
    used[must] = true;
    for (int i = 0; i < n - 1; i++) {
        if (i < must)
            used[i] = res[i];
        else
            used[i + 1] = res[i];
    }

    vector<pair<int, int>> bag;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (!used[i])
            bag.emplace_back(a[i], i);
        else if (i != must)
            c[i] = a[i];
    }
    sort(bag.begin(), bag.end());
    bag.emplace_back(a[must], must);
    reverse(bag.begin(), bag.end());

    vector<vector<int>> contain(n);
    for (size_t i = 0; i < bag.size(); i++) {
        if (i + 1 < bag.size()) {
            c[bag[i].second] = bag[i].first - bag[i + 1].first;
            contain[bag[i].second].emplace_back(bag[i + 1].second);
        } else
            c[bag[i].second] = bag[i].first;
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ' << contain[i].size();
        for (int& x : contain[i]) cout << ' ' << x + 1;
        cout << '\n';
    }
    return 0;
}