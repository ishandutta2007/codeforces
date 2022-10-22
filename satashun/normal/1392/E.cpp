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

int main() {
    int n;
    cin >> n;

    VV<ll> a(n, V<ll>(n));

    rep(i, n) {
        rep(j, n) {
            int d = i + j;
            if (d == 0 || d == (n - 1) * 2) continue;
            int p = i % 2;
            if (i % 2) {
                a[i][j] = 1ll << (n * 2 - d);
            }
        }
    }

    rep(i, n) rep(j, n) cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
    fflush(stdout);

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        // solve
        V<pii> vec;
        vec.eb(0, 0);
        int r = 0, c = 0;
        int t = (n - 1) * 2;
        rep(i, t) {
            V<pair<ll, pii>> cand;
            if (r + 1 < n) {
                cand.eb(a[r + 1][c], mp(r + 1, c));
            }
            if (c + 1 < n) {
                cand.eb(a[r][c + 1], mp(r, c + 1));
            }
            sort(ALL(cand));
            reverse(ALL(cand));
            for (auto p : cand) {
                if (p.fi <= k) {
                    k -= p.fi;
                    tie(r, c) = p.se;
                    break;
                }
            }
            vec.eb(r, c);
        }
        // debug(vec, k);
        for (auto p : vec) {
            cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
        }
        fflush(stdout);
    }

    return 0;
}