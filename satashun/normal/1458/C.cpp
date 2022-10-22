#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

const int MX = 1010;
int a[MX][MX];
int b[MX][MX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        string s;

        cin >> n >> m;
        rep(i, n) {
            rep(j, n) {
                cin >> a[i][j];
                --a[i][j];
            }
        }
        cin >> s;

        V<int> v{0, 1, 2};
        V<int> d(3);

        for (auto c : s) {
            if (c == 'I') {
                swap(v[1], v[2]);
            } else if (c == 'C') {
                swap(v[0], v[2]);
            } else if (c == 'R') {
                d[v[1]]++;
            } else if (c == 'L') {
                d[v[1]]--;
            } else if (c == 'D') {
                d[v[0]]++;
            } else {
                d[v[0]]--;
            }
        }

        rep(i, n) {
            rep(j, n) {
                V<int> u{i, j, a[i][j]};
                V<int> l(3);
                rep(k, 3) {
                    int t = u[v[k]] + d[v[k]];
                    t %= n;
                    if (t < 0) t += n;
                    l[k] = t;
                }
                b[l[0]][l[1]] = l[2];
            }
        }
        rep(i, n) {
            rep(j, n) { cout << b[i][j] + 1 << (j == n - 1 ? '\n' : ' '); }
        }
        cerr << endl;
    }
    return 0;
}