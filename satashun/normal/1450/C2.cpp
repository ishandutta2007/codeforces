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

int c[3][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;

    while (TC--) {
        int n;
        cin >> n;
        VV<int> st(n, V<int>(n, 2));
        V<string> s(n);
        rep(i, n) { cin >> s[i]; }
        rep(i, n) {
            rep(j, n) {
                if (s[i][j] != '.') {
                    st[i][j] = (s[i][j] == 'O' ? 0 : 1);
                }
            }
        }

        memset(c, 0, sizeof(c));

        int cnt = 0;

        rep(i, n) {
            rep(j, n) {
                if (s[i][j] != '.') {
                    cnt++;
                    c[(i + j) % 3][st[i][j]]++;
                }
            }
        }

        V<string> ans;
        bool done = 0;

        rep(i, 3) {
            rep(j, 3) if (i != j) {
                rep(t, 2) if (!done) {
                    if (c[i][t] + c[j][t ^ 1] <= cnt / 3) {
                        debug(i, j, t);

                        rep(a, n) {
                            rep(b, n) {
                                int l = st[a][b];
                                if ((a + b) % 3 == i && l == t) {
                                    st[a][b] ^= 1;
                                }
                                if ((a + b) % 3 == j && l == (t ^ 1)) {
                                    st[a][b] ^= 1;
                                }
                            }
                        }
                        done = true;
                    }
                }
            }
        }

        rep(i, n) {
            rep(j, n) {
                if (st[i][j] < 2) {
                    s[i][j] = (st[i][j] == 0 ? 'O' : 'X');
                }
            }
        }

        rep(i, n) { cout << s[i] << '\n'; }
    }
    return 0;
}