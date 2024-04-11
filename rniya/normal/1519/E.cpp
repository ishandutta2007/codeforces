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
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < v.size(); i++) res[v[i]] = i;
    return res;
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    auto slope = [](int a, int b, int c, int d) -> P {
        ll x = ll(a) * d, y = ll(b) * c;
        ll g = gcd(x, y);
        return make_pair(x / g, y / g);
    };
    vector<P> comp;
    vector<vector<P>> pos(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pos[i].emplace_back(slope(a + b, b, c, d));
        pos[i].emplace_back(slope(a, b, c + d, d));
        for (int j = 0; j < 2; j++) comp.emplace_back(pos[i][j]);
    }

    map<P, int> mp = compress(comp);
    int sz = mp.size();
    vector<vector<pair<int, int>>> G(sz);
    vector<vector<int>> edge(n);
    for (int i = 0; i < n; i++) {
        int x = mp[pos[i][0]], y = mp[pos[i][1]];
        G[x].emplace_back(y, i);
        G[y].emplace_back(x, i);
        edge[i].emplace_back(x);
        edge[i].emplace_back(y);
    }

    vector<bool> used(n, false), visited(sz, false);
    auto dfs1 = [&](auto self, int v) -> void {
        visited[v] = true;
        for (auto& e : G[v]) {
            int u = e.first;
            if (visited[u]) continue;
            used[e.second] = true;
            self(self, u);
        }
    };
    for (int i = 0; i < sz; i++) {
        if (visited[i]) continue;
        dfs1(dfs1, i);
    }

    vector<int> pre(sz, -1);
    vector<pair<int, int>> ans;
    auto update = [&](int x, int y) {
        if (~pre[x]) {
            ans.emplace_back(pre[x], y);
            pre[x] = -1;
        } else
            pre[x] = y;
    };
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        update(edge[i][0], i);
    }

    for (int i = 0; i < sz; i++) visited[i] = false;
    auto dfs2 = [&](auto self, int v, int p, int num) -> void {
        visited[v] = true;
        for (auto& e : G[v]) {
            int u = e.first;
            if (visited[u]) continue;
            self(self, u, v, e.second);
        }
        if (num < 0) return;
        if (~pre[v])
            update(v, num);
        else
            update(p, num);
    };
    for (int i = 0; i < sz; i++) {
        if (visited[i]) continue;
        dfs2(dfs2, i, -1, -1);
    }

    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    return 0;
}