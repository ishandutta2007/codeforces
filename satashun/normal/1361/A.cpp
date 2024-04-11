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

const int maxn = 500010;

V<int> g[maxn];
set<int> st[maxn];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    rep(i, m) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    V<pii> vec(n);
    rep(i, n) {
        int x;
        scanf("%d", &x);
        vec[i] = mp(x, i);
    }
    sort(ALL(vec));

    V<int> p(n);
    rep(i, n) {
        int x = 1;
        int v = vec[i].se;
        int val = vec[i].fi;
        p[i] = v;
        while (st[v].count(x)) {
            ++x;
        }
        if (x != val) {
            puts("-1");
            return 0;
        }
        for (int to : g[v]) {
            st[to].insert(val);
        }
    }
    rep(i, n) { printf("%d%c", p[i] + 1, i == n - 1 ? '\n' : ' '); }

    return 0;
}