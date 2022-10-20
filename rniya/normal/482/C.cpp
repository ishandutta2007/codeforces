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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

double solve(int n, vector<string> S) {
    int m = S[0].size();

    vector<vector<int>> diff(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (S[i][k] != S[j][k]) {
                    diff[i][j] |= 1 << k;
                }
            }
        }
    }

    vector<double> dp(1 << m);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        fill(ALL(dp), 0);
        for (int mask = (1 << m) - 1; mask >= 0; mask--) {
            bool identified = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (!(diff[i][j] & mask)) {
                    identified = false;
                }
            }
            if (identified) {
                dp[mask] = 0;
                continue;
            }

            int unused = m - __builtin_popcount(mask);
            for (int j = 0; j < m; j++) {
                if (!(mask >> j & 1)) {
                    dp[mask] += (dp[mask | 1 << j] + 1) / unused;
                }
            }
        }
        ans += dp[0] / n;
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<string> S(n);
    cin >> S;
    int m = S[0].size();

    vector<ll> ng(1 << m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int mask = 0;
            for (int k = 0; k < m; k++) mask |= (S[i][k] == S[j][k]) << k;
            ng[mask] |= 1LL << i;
        }
    }

    for (int mask = (1 << m) - 1; mask >= 0; mask--) {
        for (int i = 0; i < m; i++) {
            if (mask & 1 << i) {
                ng[mask ^ (1 << i)] |= ng[mask];
            }
        }
    }

    vector<double> prob(m + 1, 0);
    prob[0] = double(1) / n;
    for (int i = 0; i < m; i++) prob[i + 1] = prob[i] * (i + 1) / (m - i);

    double ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += (ng[mask] & 1LL << i) >> i;
        int flag = 0;
        for (int i = 0; i < m; i++) flag += (mask >> i & 1);
        if (cnt == 0) continue;
        ans += prob[flag] * cnt;
    }

    cout << ans << '\n';
    return 0;
}