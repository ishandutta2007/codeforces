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
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < (int)v.size(); i++) res[v[i]] = i;
    return res;
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++) cin >> l[i] >> r[i];

    sort(ALL(a));
    vector<int> xs;
    for (int& x : a) xs.emplace_back(x);
    for (int& x : l) xs.emplace_back(x);
    for (int& x : r) xs.emplace_back(x);
    map<int, int> mp = compress(xs);
    for (int& x : a) x = mp[x];
    for (int& x : l) x = mp[x];
    for (int& x : r) x = mp[x];
    int N = mp.size();

    vector<bool> used(m, false);  //  visited  segment  cover 
    {
        vector<int> imos(N + 1, 0);
        for (int i = 0; i < n; i++) imos[a[i] + 1]++;
        for (int i = 0; i < N; i++) imos[i + 1] += imos[i];
        for (int i = 0; i < m; i++) {  //  visited 
            int cnt = imos[r[i] + 1] - imos[l[i]];
            if (cnt > 0) used[i] = true;
        }
    }

    {
        vector<int> idx(m);
        iota(ALL(idx), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            if (r[x] != r[y]) return r[x] < r[y];
            return l[x] > l[y];
        });
        int Max_l = -INF;
        for (int& i : idx) {  //  segment  cover 
            if (used[i]) continue;
            if (l[i] <= Max_l) used[i] = true;
            chmax(Max_l, l[i]);
        }
        // debug(used);
    }

    {
        // used 
        vector<pair<int, int>> interval;
        for (int i = 0; i < m; i++) {
            if (used[i]) continue;
            interval.emplace_back(l[i], r[i]);
        }
        sort(ALL(interval));
        m = interval.size();
        l.clear();
        r.clear();
        for (auto& p : interval) {
            l.emplace_back(p.first);
            r.emplace_back(p.second);
        }
        // for (int i = 0; i < m; i++) cerr << xs[l[i]] << (i + 1 == m ? '\n' : ' ');
        // for (int i = 0; i < m; i++) cerr << xs[r[i]] << (i + 1 == m ? '\n' : ' ');
    }

    vector<ll> dp(m + 1, IINF);
    dp[0] = 0;
    for (int i = 0, pre = 0; i < n; i++) {
        int cur = pre;
        while (cur < m && r[cur] < a[i]) cur++;
        int nxt = cur;
        if (i + 1 < n) {
            while (nxt < m && r[nxt] < a[i + 1]) nxt++;
        } else
            nxt = m;
        // -> <-
        {
            ll cost = dp[cur];  // 
            for (int k = pre; k < cur; k++) {
                chmin(cost, dp[k] + ll(xs[a[i]] - xs[r[k]]));
            }
            for (int k = cur; k < nxt; k++) chmin(dp[k + 1], cost + 2LL * ll(xs[l[k]] - xs[a[i]]));
        }
        // <- ->
        {
            ll cost = dp[cur];  // 
            for (int k = pre; k < cur; k++) {
                chmin(cost, dp[k] + 2LL * ll(xs[a[i]] - xs[r[k]]));
                chmin(dp[cur], dp[k] + ll(xs[a[i]] - xs[r[k]]));  // <- 
            }
            for (int k = cur; k < nxt; k++) chmin(dp[k + 1], cost + ll(xs[l[k]] - xs[a[i]]));
        }
        pre = cur;
    }

    ll ans = dp[m];
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