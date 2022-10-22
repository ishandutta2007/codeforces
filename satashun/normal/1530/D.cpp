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

ll rand_int(ll l, ll r) {  //[l,r]
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

// FisherYates
template <class T>
vector<T> random_perm(vector<T> vec) {
    vector<T> res;
    rep(i, vec.size()) {
        res.pb(vec[i]);
        int j = rand_int(0, i);
        swap(res[j], res[i]);
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        V<int> a(n);
        rep(i, n) cin >> a[i], --a[i];
        VV<int> p(n);
        rep(i, n) p[a[i]].pb(i);
        V<int> b(n, -1), tb(n, -1), used(n);

        int ok = 0;
        rep(i, n) {
            if (SZ(p[i])) {
                ok++;
                b[p[i][0]] = i;
                tb[i] = p[i][0];
                used[i] = 1;
            }
        }

        V<int> fr, to;
        rep(i, n) if (b[i] == -1) fr.pb(i);
        rep(i, n) if (!used[i]) to.pb(i);

        if (SZ(fr) == 1 && to[0] == fr[0]) {
            int p = to[0];
            b[p] = a[p];
            b[tb[a[p]]] = -1;
            fr.clear();
            rep(i, n) if (b[i] == -1) fr.pb(i);
        }

        debug(b, fr, to);
        while (true) {
            to = random_perm(to);
            bool f = 1;
            rep(i, SZ(to)) {
                if (fr[i] == to[i]) {
                    f = 0;
                }
            }
            if (f) {
                rep(i, SZ(to)) { b[fr[i]] = to[i]; }
                break;
            }
        }

        cout << ok << '\n';
        rep(i, n) cout << b[i] + 1 << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}