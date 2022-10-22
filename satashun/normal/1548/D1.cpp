//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

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

// int c[6010][6010];
ll cnt[4][4];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    V<pii> pt;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        pt.eb(a, b);
        cnt[a % 4][b % 4]++;
    }

    set<V<pii>> vis;

    ll ans = 0;

    rep(i, 1 << 6) {
        V<pii> pari;
        V<int> p(6);
        rep(j, 6) p[j] = i >> j & 1;
        rep(j, 3) { pari.eb(p[j * 2] * 2, p[j * 2 + 1] * 2); }
        sort(ALL(pari));
        if (vis.count(pari)) continue;
        vis.insert(pari);

        int bound = 0;
        rep(j, 3) {
            rep(k, j) {
                if (pari[k].fi == pari[j].fi && pari[k].se == pari[j].se) {
                    //
                } else {
                    bound++;
                }
            }
        }
        if (bound % 2 == 0) {
            ll val = 1;
            rep(j, 3) {
                val *= cnt[pari[j].fi][pari[j].se];
                --cnt[pari[j].fi][pari[j].se];
            }

            if (pari[0] == pari.back()) {
                val /= 6;
            } else {
                bool t = 0;
                rep(j, 2) {
                    if (pari[j + 1] == pari[j]) t = 1;
                }
                if (t) val /= 2;
            }
            ans += val;

            rep(j, 3) { ++cnt[pari[j].fi][pari[j].se]; }
            // debug(pari);
        }
    }
    /*
        rep(i, n) {
            rep(j, i) {
                int d = gcd(abs(pt[i].fi - pt[j].fi), abs(pt[i].se - pt[j].se));
                c[i][j] = c[j][i] = d;
                debug(i, j, c[i][j]);
            }
        }

        rep(i, n) {
            rep(j, i) {
                rep(k, j) {
                    if ((c[i][j] + c[i][k] + c[j][k]) % 4 == 0) {
                        debug(i, j, k);
                    }
                }
            }
        }
    */
    cout << ans << endl;

    return 0;
}