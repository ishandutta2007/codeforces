//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

const ll INF = 1e15;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n[4];
    rep(i, 4) cin >> n[i];
    VV<ll> a(4);

    rep(i, 4) {
        a[i].resize(n[i]);
        rep(j, n[i]) cin >> a[i][j];
    }

    {
        int m;
        cin >> m;
        multiset<ll> st;
        for (int x : a[0]) st.insert(x);
        VV<int> ng(n[1]);

        rep(i, m) {
            int p, q;
            cin >> p >> q;
            --p, --q;
            ng[q].pb(p);
        }

        rep(i, n[1]) {
            for (int to : ng[i]) {
                st.erase(st.find(a[0][to]));
            }
            if (st.size()) {
                a[1][i] += *st.begin();
            } else {
                a[1][i] = INF;
            }
            for (int to : ng[i]) {
                st.insert(a[0][to]);
            }
        }
    }

    V<pii> es;
    int m2;
    cin >> m2;
    rep(i, m2) {
        int p, q;
        cin >> p >> q;
        --p, --q;
        es.eb(p, q);
    }

    {
        int m;
        cin >> m;
        multiset<ll> st;
        for (int x : a[3]) st.insert(x);
        VV<int> ng(n[2]);

        rep(i, m) {
            int p, q;
            cin >> p >> q;
            --p, --q;
            ng[p].pb(q);
        }

        rep(i, n[2]) {
            for (int to : ng[i]) {
                st.erase(st.find(a[3][to]));
            }
            if (st.size()) {
                a[2][i] += *st.begin();
            } else {
                a[2][i] = INF;
            }
            for (int to : ng[i]) {
                st.insert(a[3][to]);
            }
        }
    }

    ll ans = INF;

    {
        multiset<ll> st;
        for (auto x : a[1]) st.insert(x);
        VV<int> ng(n[2]);
        debug(es);
        for (auto e : es) {
            int p, q;
            tie(p, q) = e;
            ng[q].pb(p);
        }

        rep(i, n[2]) {
            if (a[2][i] != INF) {
                for (int to : ng[i]) {
                    st.erase(st.find(a[1][to]));
                }
                if (st.size()) {
                    chmin(ans, a[2][i] + *st.begin());
                }
                for (int to : ng[i]) {
                    st.insert(a[1][to]);
                }
            }
        }
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}