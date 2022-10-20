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

bool check(string s, string t, int a, int b, int k) {
    int A = 0, B = 0;
    if (s[0] != '1') return false;
    if (t[0] != '1') return false;
    for (auto& c : s) A += c - '0';
    for (auto& c : t) B += c - '0';
    if (A != b || B != b) return false;
    string u(a + b, '0');
    int pre = 0;
    for (int i = a + b - 1; i >= 0; i--) {
        int x = s[i] - '0', y = t[i] - '0';
        if (x >= y + pre) {
            u[i] = '0' + (x - y - pre) % 2;
            pre = 0;
        } else {
            u[i] = '0' + (x - y - pre + 2) % 2;
            pre = 1;
        }
    }
    if (pre) return false;
    int one = 0;
    for (auto& c : u) one += c - '0';
    return one == k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, k;
    cin >> a >> b >> k;

    if (k == a + b) {
        cout << "No" << '\n';
        return 0;
    }
    if (b <= 1 && k) {
        cout << "No" << '\n';
        return 0;
    }

    int n = a + b;
    string S(n, '0'), T(n, '0');
    S[n - 1 - k] = '1';
    T[n - 1] = '1';
    int nb = b;
    b--;
    for (int i = 0; i < n; i++) {
        if (b && S[i] == T[i] && S[i] == '0') {
            S[i] = '1';
            T[i] = '1';
            b--;
        }
    }
    int cur = 0;
    while (S[cur] == '0' && T[cur] == '0') {
        S += '0';
        T += '0';
        cur++;
    }
    S = S.substr(cur, n), T = T.substr(cur, n);

    if (!check(S, T, a, nb, k)) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    cout << S << '\n';
    cout << T << '\n';
    return 0;
}