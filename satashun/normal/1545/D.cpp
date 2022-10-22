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
    int m, k;
    cin >> m >> k;
    V<ll> s1(k), s2(k);
    auto a = make_vec<ll>(k, m);
    rep(i, k) {
        rep(j, m) {
            cin >> a[i][j];
            s1[i] += a[i][j];
            s2[i] += a[i][j] * a[i][j];
        }
    }
    map<ll, int> d1;
    rep(i, k - 1) { d1[s1[i + 1] - s1[i]]++; }
    ll real1;
    {
        int mx = 0;
        for (auto& [x, c] : d1) {
            if (mx < c) {
                mx = c;
                real1 = x;
            }
        }
    }

    int y = -1;
    for (int i = 1; i < k - 1; ++i) {
        if (s1[i] - s1[i - 1] != real1 && s1[i + 1] - s1[i] != real1) {
            y = i;
        }
    }

    ll real2;
    if (y >= 3) {
        real2 = (s2[2] + s2[0] - s2[1] * 2) / 2;
    } else {
        real2 = (s2[k - 1] + s2[k - 3] - s2[k - 2] * 2) / 2;
    }

    ll p1 = real1 - (s1[y] - s1[y - 1]);

    ll ans = -1;
    rep(j, m) {
        ll ns = s2[y] + (a[y][j] + p1) * (a[y][j] + p1) - a[y][j] * a[y][j];
        if (ns * 2 == s2[y - 1] + s2[y + 1] - real2 * 2) {
            ans = a[y][j] + p1;
        }
    }
    debug(real1, real2, p1, ans);
    cout << y << " " << ans << endl;

    cout.flush();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc = 1;
    while (tc--) {
        slv();
    }
    return 0;
}