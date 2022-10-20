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

string gen(int n, int mask) {
    string res = "";
    for (int i = 0; i < n; i++) res += (mask >> i & 1 ? '1' : '0');
    return res;
}

map<string, int> tle(int n) {
    vector<map<string, int>> mp(2);
    auto solve = [&](auto self, int turn, string& s) -> int {
        if (mp[turn].count(s)) return mp[turn][s];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' != turn) continue;
            if (i + 1 < n) {
                char tmp1 = s[i], tmp2 = s[i + 1];
                s[i] = s[i + 1] = '2';
                int ch = self(self, turn ^ 1, s);
                s[i] = tmp1, s[i + 1] = tmp2;
                if (ch == 0) {
                    res = 1;
                    break;
                }
            }
            if (i - 1 >= 0) {
                char tmp1 = s[i], tmp2 = s[i - 1];
                s[i] = s[i - 1] = '2';
                int ch = self(self, turn ^ 1, s);
                s[i] = tmp1, s[i - 1] = tmp2;
                if (ch == 0) {
                    res = 1;
                    break;
                }
            }
        }
        return mp[turn][s] = res;
    };
    for (int mask = 0; mask < (1 << n); mask++) {
        string s = gen(n, mask);
        solve(solve, 0, s);
    }
    return mp[0];
}

const int MAX = 1000, C = 34;
int dp[MAX];

void precalc() {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < MAX; i++) {
        set<int> s;
        s.emplace(dp[i - 2]);
        for (int l = 0; i - 3 - l >= 0; l++) {
            int r = i - 3 - l;
            s.emplace(dp[l] ^ dp[r]);
        }
        for (int j = 0;; j++) {
            if (!s.count(j)) {
                dp[i] = j;
                break;
            }
        }
    }
    // for (int i = 0; i < C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
    // for (int i = C; i < 2 * C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
    // for (int i = 2 * C; i < 3 * C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
    // for (int i = 3 * C; i < 4 * C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
    // for (int i = 4 * C; i < 5 * C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
    // for (int i = 5 * C; i < 6 * C; i++) cerr << dp[i] << ' ';
    // cerr << '\n';
}

int solve(int n, string S) {
    int one = 0;
    for (char& c : S) one += (c == 'R');
    if (one * 2 > n) return 1;
    if ((n - one) * 2 > n) return 0;

    int grundy = 0;
    auto calc = [&](int x) {
        if (x < MAX) return dp[x];
        return dp[x % C + 2 * C];
    };
    for (int i = 0, seq = 0; i < n; i++) {
        if (i == n - 1 or S[i] == S[i + 1]) {
            grundy ^= calc(seq);
            seq = 0;
        } else {
            seq++;
        }
    }

    // debug(S, grundy);
    return grundy;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    precalc();
    int t;
    cin >> t;
    for (; t--;) {
        int n;
        string S;
        cin >> n >> S;
        cout << (solve(n, S) ? "Alice" : "Bob") << '\n';
    }
    return 0;
}