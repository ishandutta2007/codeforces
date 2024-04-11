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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m1, m2, t;
    cin >> n >> m1 >> m2 >> t;
    vector<int> x(m1), y(m2), pos;
    pos.emplace_back(0);
    set<pair<int, int>> obs;
    for (int i = 0; i < m1; i++) {
        cin >> x[i];
        pos.emplace_back(x[i]);
        pos.emplace_back(x[i] + 1);
        obs.emplace(x[i], 0);
    }
    for (int i = 0; i < m2; i++) {
        cin >> y[i];
        pos.emplace_back(y[i]);
        pos.emplace_back(y[i] + 1);
        obs.emplace(y[i], 1);
    }
    pos.emplace_back(n + 1);

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    int N = pos.size();
    vector<vector<int>> dp(N, vector<int>(2, -INF));
    vector<vector<pair<int, int>>> pre(N, vector<pair<int, int>>(2, {-1, -1}));
    dp[0][0] = dp[0][1] = 0;
    pre[0][1] = {0, 0};

    auto check = [&](int p, int q) {
        if (!q) {
            auto itr = lower_bound(x.begin(), x.end(), p);
            if (itr != x.end()) return *itr == p;
        } else {
            auto itr = lower_bound(y.begin(), y.end(), p);
            if (itr != y.end()) return *itr == p;
        }
        return false;
    };
    auto update = [&](int nx, int ny, int x, int y, int val) {
        if (val <= dp[nx][ny]) return;
        dp[nx][ny] = val;
        pre[nx][ny] = {x, y};
    };

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[i - 1][j] < 0) continue;
            int nxt = dp[i - 1][j] + (pos[i] - pos[i - 1]);
            if (check(pos[i], j)) {
                if (nxt - 1 >= t) {
                    update(i, j, i - 1, j, nxt - t);
                }
            } else
                update(i, j, i - 1, j, nxt);
        }
        for (int j = 0; j < 2; j++) {
            if (dp[i][j ^ 1] >= 0 && !check(pos[i], j)) {
                update(i, j, i, j ^ 1, min(t, dp[i][j ^ 1]));
            }
        }
    }

    if (dp[N - 1][0] < 0) {
        cout << "No" << '\n';
        return 0;
    }

    vector<int> move;
    vector<pair<int, int>> shot;
    int X = N - 1, Y = 0, preshot = INF;

    while (!(X == 0 && Y == 0)) {
        int PX = pre[X][Y].first, PY = pre[X][Y].second;
        if (X == PX && Y != PY)
            move.emplace_back(pos[X]);
        else if (dp[X][Y] < dp[PX][PY] + (pos[X] - pos[PX])) {
            shot.emplace_back(min(preshot - t, pos[X] - 1), Y);
            preshot = min(preshot - t, pos[X] - 1);
        }
        X = PX, Y = PY;
    }
    reverse(move.begin(), move.end());
    reverse(shot.begin(), shot.end());

    cout << "Yes" << '\n';
    int a = move.size(), b = shot.size();
    cout << a << '\n';
    for (int i = 0; i < a; i++) cout << move[i] << (i + 1 == a ? '\n' : ' ');
    cout << b << '\n';
    for (auto& p : shot) cout << p.first << ' ' << p.second + 1 << '\n';
    return 0;
}