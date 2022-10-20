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

const int MAX_LOG = 20;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int m;
    cin >> m;

    int n = S.size();
    auto next = [](int k, int d) {
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < k; i++) v.emplace_back(i % d, i / d, i);
        sort(ALL(v));
        vector<int> res(k);
        for (int i = 0; i < k; i++) res[get<2>(v[i])] = i - 1;
        return res;
    };
    auto query = [&](int k, int d) {
        vector<int> v = next(k, d);
        vector<vector<int>> dp(MAX_LOG, vector<int>(k, -1));
        for (int i = 0; i < k; i++) dp[0][i] = v[i];
        for (int i = 0; i < MAX_LOG - 1; i++) {
            for (int j = 0; j < k; j++) {
                int nxt = dp[i][j];
                if (~nxt) dp[i + 1][j] = dp[i][nxt];
            }
        }

        // debug(v);
        vector<pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            int cnt = (i < k ? n - k + 1 : n - i), cur = min(k - 1, i), base = max(0, i - k + 1), to = cur;
            for (int j = MAX_LOG - 1; j >= 0; j--) {
                if (cnt >> j & 1) {
                    to = (to < 0 ? to : dp[j][to]);
                }
            }
            // debug(i, cnt, cur, base, to, base + cnt + to);
            if (~to) {
                pos.emplace_back(base + cnt + to, i);
                continue;
            }
            int used = 0;
            for (int j = MAX_LOG - 1; j >= 0; j--) {
                if (~dp[j][cur]) {
                    used |= 1 << j;
                    cur = dp[j][cur];
                }
            }
            assert(used < cnt);
            pos.emplace_back(base + used, i);
        }

        sort(ALL(pos));
        string res = "";
        // debug(S, pos);
        for (auto& p : pos) res += S[p.second];
        return S = res;
    };

    for (; m--;) {
        int k, d;
        cin >> k >> d;
        cout << query(k, d) << '\n';
    }
    return 0;
}