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

void slv() {
    int n, k;
    cin >> n >> k;
    V<pii> rng(k);

    V<int> st(n * 2);
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (x > y) swap(x, y);
        rng[i] = mp(x, y);
        st[x] = 1;
        st[y] = -1;
    }

    int sz = n * 2;
    V<int> fr;
    rep(i, sz) if (st[i] == 0) fr.pb(i);

    auto intersect = [&](pii a, pii b) {
        if (a.fi > b.fi) swap(a, b);
        return a.se >= b.fi && a.se <= b.se;
    };

    auto dp = make_vec<int>(sz + 1);
    auto sc = make_vec<int>((n - k) * 2, (n - k) * 2);

    rep(i, (n - k) * 2) {
        rep(j, i) {
            int c = 0;
            for (auto p : rng) {
                if (intersect(mp(fr[j], fr[i]), p)) c++;
            }
            sc[j][i] = c;
        }
    }

    rep(i, n - k) {
        for (int j = i; j < n - k; ++j) {
            V<pii> pr;
            int c = j - i + 1;
            int p = i * 2; /*
             for (int a = i; a <= j; ++a, ++p) {
                 pr.eb(fr[p], fr[p + c]);
             }*/
            int ct = c * (c - 1) / 2;

            for (int a = i; a <= j; ++a, ++p) {
                ct += sc[p][p + c];
            }
            chmax(dp[j + 1], dp[i] + ct);
        }
    }
    int ans = dp[n - k];
    rep(i, k) {
        rep(j, i) {
            if (intersect(rng[j], rng[i])) ans++;
        }
    }
    cout << ans << endl;
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