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
 * @brief 
 */
template <typename T> bool is_prime(T n) {
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return 1 < n;
}

/**
 * @brief 2
 */
long long modpow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1LL) res = res * x % mod;
        x = x * x % mod;
        n >>= 1LL;
    }
    return res;
}
long long modinv(long long x, long long p) { return modpow(x, p - 2, p); }

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

bool check(int n, const vector<int>& v) {
    ll mul = 1;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        mul *= v[i];
        if (mul >= n) mul %= n;
        if (seen[mul]) return false;
        seen[mul] = true;
    }
    return true;
}

vector<vector<int>> tle(int n) {
    vector<vector<int>> res;
    vector<int> perm(n - 2);
    iota(ALL(perm), 2);

    do {
        vector<int> v(n);
        v[0] = 1, v[n - 1] = n;
        for (int i = 1; i < n - 1; i++) v[i] = perm[i - 1];

        if (check(n, v)) res.emplace_back(v);
    } while (next_permutation(ALL(perm)));

    return res;
}

const int MAX_ITER = 100;

void solve(int n) {
    vector<int> res;
    if (n == 1) {
        cout << "YES" << '\n';
        cout << 1 << '\n';
        return;
    }
    if (n == 4) {
        cout << "YES" << '\n';
        for (int x : {1, 3, 2, 4}) cout << x << '\n';
        return;
    }
    if (n != 4 && !is_prime(n)) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    res.emplace_back(1);
    for (int i = 2; i < n; i++) {
        ll inv = modinv(i - 1, n);
        res.emplace_back(inv * i % n);
    }
    res.emplace_back(n);

    assert(check(n, res));
    for (int& x : res) cout << x << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    solve(n);
    return 0;
}