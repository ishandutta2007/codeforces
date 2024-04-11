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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    VV<int> vec(n);
    rep(i, n * k) {
        int c;
        cin >> c;
        --c;
        vec[c].pb(i);
    }

    V<pii> ans(n);
    V<int> use(n);

    for (int i = 0; i < n; i += k - 1) {
        int num = min(n, i + k - 1) - i;

        int la = -1;
        rep(t, num) {
            V<pii> rng;
            for (int j = i; j < min(n, i + k - 1); ++j) {
                if (!use[j]) {
                    rep(p, k - 1) {
                        if (vec[j][p] > la) {
                            rng.eb(vec[j][p + 1], j);
                            break;
                        }
                    }
                }
            }
            sort(ALL(rng));
            debug(rng);
            use[rng[0].se] = 1;
            int j = rng[0].se;
            rep(p, k - 1) {
                if (vec[j][p] > la) {
                    ans[j] = mp(vec[j][p], vec[j][p + 1]);
                    break;
                }
            }
            la = rng[0].fi;
        }
    }
    debug(ans);
    rep(i, n) { cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << endl; }

    return 0;
}