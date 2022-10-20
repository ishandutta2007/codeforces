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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    map<vector<int>, vector<int>> mp;
    for (int i = n - 1; i >= 0; i--) mp[a[i]].emplace_back(i);
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        if (!mp.count(b[i]) || mp[b[i]].empty()) {
            cout << -1 << '\n';
            return 0;
        }
        num[i] = mp[b[i]].back();
        mp[b[i]].pop_back();
    }

    vector<vector<int>> edge(n - 1, vector<int>(m));
    vector<int> ng(m, 0), suggest(m, 0);  // ng
    vector<bool> start(n - 1);            // 
    vector<bool> used(m, false);          // 
    vector<bool> ok(n - 1, false);        // 

    for (int i = 0; i < n - 1; i++) {
        int p = num[i], q = num[i + 1];
        start[i] = (p < q);
        for (int j = 0; j < m; j++) {
            if (a[p][j] == a[q][j])
                edge[i][j] = 0;
            else if (a[p][j] < a[q][j])
                edge[i][j] = 2, suggest[j]++;
            else
                edge[i][j] = 1, ng[j]++;
        }
    }

    vector<int> ans;
    auto solve = [&]() -> bool {
        bool end = true;
        for (int i = 0; i < n - 1; i++) {
            if (!start[i] && !ok[i]) {
                end = false;
            }
        }
        if (end) return true;

        int nxt = -1;
        for (int i = 0; i < m; i++) {
            if (ng[i] > 0) continue;
            if (suggest[i] == 0) continue;
            if (used[i]) continue;
            nxt = i;
        }
        if (nxt < 0) {
            cout << -1 << '\n';
            exit(0);
        }

        ans.emplace_back(nxt + 1);
        for (int i = 0; i < n - 1; i++) {
            if (ok[i]) continue;
            if (edge[i][nxt] == 2) {
                ok[i] = true;
                for (int j = 0; j < m; j++) {
                    if (edge[i][j] == 1) {
                        ng[j]--;
                    } else if (edge[i][j] == 2) {
                        suggest[j]--;
                    }
                }
            }
        }
        return false;
    };

    // TODO: fix
    while (1) {
        // for (int i = 0; i < 10; i++) {
        bool res = solve();
        // debug(res, ok, start);
        if (res) break;
    }

    reverse(ALL(ans));
    cout << ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}