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
#define ALL(c) (c).begin(), (c).end()

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

bool f[1010][1010], nx[1010][1010], nx2[1010][1010];

int main() {
    int n, m;
    cin >> n >> m;
    V<string> s(n);
    rep(i, n) cin >> s[i];
    int si, sj, ti, tj;
    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (s[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }
    f[si][sj] = 1;

    rep(t, 3) {
        rep(i, n) {
            rep(j, m) { nx[i][j] = f[i][j]; }
        }
        rep(i, n) {
            rep(j, m) { nx2[i][j] = f[i][j]; }
        }
        rep(i, n - 1) {
            rep(j, m) {
                if (s[i + 1][j] != '*') {
                    nx2[i + 1][j] |= nx2[i][j];
                }
            }
        }
        rep(i, n) {
            rep(j, m) { nx[i][j] |= nx2[i][j]; }
        }
        rep(i, n) {
            rep(j, m) { nx2[i][j] = f[i][j]; }
        }
        rep(i, n) {
            rep(j, m - 1) {
                if (s[i][j + 1] != '*') {
                    nx2[i][j + 1] |= nx2[i][j];
                }
            }
        }
        rep(i, n) {
            rep(j, m) { nx[i][j] |= nx2[i][j]; }
        }
        rep(i, n) {
            rep(j, m) { nx2[i][j] = f[i][j]; }
        }
        for (int i = n - 2; i >= 0; --i) {
            rep(j, m) {
                if (s[i][j] != '*') {
                    nx2[i][j] |= nx2[i + 1][j];
                }
            }
        }
        rep(i, n) {
            rep(j, m) { nx[i][j] |= nx2[i][j]; }
        }
        rep(i, n) {
            rep(j, m) { nx2[i][j] = f[i][j]; }
        }
        rep(i, n) {
            for (int j = m - 2; j >= 0; --j) {
                if (s[i][j] != '*') {
                    nx2[i][j] |= nx2[i][j + 1];
                }
            }
        }
        rep(i, n) {
            rep(j, m) { nx[i][j] |= nx2[i][j]; }
        }
        rep(i, n) {
            rep(j, m) { f[i][j] = nx[i][j]; }
        }
    }
    puts(f[ti][tj] ? "YES" : "NO");
    return 0;
}