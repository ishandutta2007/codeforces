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

const int MAX_N = 10, MAX_L = 110, MAX = 52;
int nxt[MAX_N][MAX_L][MAX + 1], pos[MAX_N][MAX + 1][2], sz[MAX_N], idx[MAX_N][MAX_L];
string dp[MAX + 1][1 << MAX_N];

int ctoi(char c) {
    if (c <= 'Z') return c - 'A';
    return 26 + (c - 'a');
}

char itoc(int x) {
    if (x < 26) return 'A' + x;
    return 'a' + (x - 26);
}

void solve() {
    int n;
    cin >> n;

    vector<int> ord;
    ord.emplace_back(MAX);
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        int l = S.size();
        sz[i] = l;
        if (i == 0) {
            for (char& c : S) {
                ord.emplace_back(ctoi(c));
            }
        }
        for (int k = 0; k <= MAX; k++) nxt[i][l][k] = l;
        for (int j = 0; j <= MAX; j++) {
            for (int k = 0; k < 2; k++) {
                pos[i][j][k] = l;
            }
        }
        vector<int> cnt(MAX, 0);
        for (int j = l - 1; j >= 0; j--) {
            for (int k = 0; k <= MAX; k++) nxt[i][j][k] = nxt[i][j + 1][k];
            int x = ctoi(S[j]);
            nxt[i][j][x] = j;
        }
        for (int j = 0; j < l; j++) {
            int x = ctoi(S[j]);
            idx[i][j] = cnt[x];
            pos[i][x][cnt[x]++] = j;
        }
        pos[i][MAX][0] = -1;
    }

    auto update = [&](int i, int mask, const string& s) {
        if (dp[i][mask].size() < s.size()) dp[i][mask] = s;
    };
    for (int i = 0; i <= MAX; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[i][mask] = "";
        }
    }

    vector<int> cur(n), ncur(n);
    string ans = "";
    for (int& i : ord) {
        for (int mask = 0; mask < (1 << n); mask++) {
            string& val = dp[i][mask];
            if (ans.size() < val.size()) ans = val;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                cur[j] = pos[j][i][mask >> j & 1];
                if (cur[j] >= sz[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            // debug(i, mask, cur);
            for (int j = 0; j < MAX; j++) {
                bool ok2 = true;
                for (int k = 0; k < n; k++) {
                    ncur[k] = nxt[k][cur[k] + 1][j];
                    if (ncur[k] >= sz[k]) {
                        ok2 = false;
                        break;
                    }
                }
                if (!ok2) continue;
                int nmask = 0;
                for (int k = 0; k < n; k++) nmask |= (idx[k][ncur[k]]) << k;
                val += itoc(j);
                update(j, nmask, val);
                // debug(j, nmask, dp[j][nmask]);
                val.pop_back();
            }
        }
    }

    // for (int mask = 0; mask < (1 << n); mask++) {
    //     for (int i = MAX; i >= 0; i--) {
    //         string& val = dp[i][mask];
    //         if (val != "") {
    //             debug(i, mask, val);
    //         }
    //         if (ans.size() < val.size()) ans = val;
    //         bool ok = true;
    //         for (int j = 0; j < n; j++) {
    //             cur[j] = pos[j][i][mask >> j & 1];
    //             if (cur[j] >= sz[j]) {
    //                 ok = false;
    //                 break;
    //             }
    //         }
    //         if (!ok) continue;
    //         // debug(i, mask, cur);
    //         for (int j = 0; j < MAX; j++) {
    //             bool ok2 = true;
    //             for (int k = 0; k < n; k++) {
    //                 ncur[k] = nxt[k][cur[k] + 1][j];
    //                 if (ncur[k] >= sz[k]) {
    //                     ok2 = false;
    //                     break;
    //                 }
    //             }
    //             if (!ok2) continue;
    //             int nmask = 0;
    //             for (int k = 0; k < n; k++) nmask |= (idx[k][ncur[k]]) << k;
    //             val += itoc(j);
    //             update(j, nmask, val);
    //             // debug(j, nmask, dp[j][nmask]);
    //             val.pop_back();
    //         }
    //     }
    // }

    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}