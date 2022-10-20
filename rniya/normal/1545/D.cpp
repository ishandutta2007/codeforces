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
    int m, k;
    cin >> m >> k;
    vector<vector<int>> a(k, vector<int>(m));
    vector<int> sum1(k, 0);
    vector<ll> sum2(k, 0);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum1[i] += a[i][j];
            sum2[i] += ll(a[i][j]) * a[i][j];
        }
    }

    int diff = (sum1[k - 1] - sum1[0]) / (k - 1), row = -1, error = -1;
    for (int i = 0; i < k; i++) {
        if (sum1[i] != sum1[0] + diff * i) {
            row = i;
            error = (sum1[0] + diff * i) - sum1[i];
            break;
        }
    }
    int correct = -1;
    for (int i = 1; i < k - 1; i++) {
        if (i != row) {
            correct = i;
            break;
        }
    }

    vector<vector<int>> coef(2, vector<int>(2));
    coef[0][0] = 2 * correct;
    coef[0][1] = correct * correct;
    coef[1][0] = 2 * (k - 1);
    coef[1][1] = (k - 1) * (k - 1);

    ll vv = ((sum2[k - 1] - sum2[0]) * correct - (sum2[correct] - sum2[0]) * (k - 1)) /
            (coef[1][1] * correct - coef[0][1] * (k - 1));
    ll vx = (sum2[k - 1] - sum2[0] - vv * coef[1][1]) / coef[1][0];
    ll true_sum = sum2[0] + 2 * vx * row + vv * row * row;

    for (int j = 0; j < m; j++) {
        sum2[row] -= ll(a[row][j]) * a[row][j];
        a[row][j] += error;
        sum2[row] += ll(a[row][j]) * a[row][j];
        if (sum2[row] == true_sum) {
            cout << row << ' ' << a[row][j] << endl;
            return 0;
        }
        sum2[row] -= ll(a[row][j]) * a[row][j];
        a[row][j] -= error;
        sum2[row] += ll(a[row][j]) * a[row][j];
    }
    return 0;
}