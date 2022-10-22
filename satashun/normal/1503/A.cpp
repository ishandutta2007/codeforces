//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = uint64_t;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

void slv() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != '1' || s[n - 1] != '1') {
        cout << "NO\n";
        return;
    }
    int c0 = 0, c1 = 0;
    for (auto c : s) {
        if (c == '0')
            c0++;
        else
            c1++;
    }
    if (c0 % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int p0 = 0, p1 = 0;
    string t = s, u = s;
    rep(i, n) {
        if (s[i] == '1') {
            if (p1 < c1 / 2) {
                t[i] = '(';
                u[i] = '(';
            } else {
                t[i] = ')';
                u[i] = ')';
            }
            p1++;
        } else {
            if (p0) {
                t[i] = '(';
                u[i] = ')';
            } else {
                u[i] = '(';
                t[i] = ')';
            }
            p0 ^= 1;
        }
    }
    cout << t << '\n';
    cout << u << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }
    return 0;
}