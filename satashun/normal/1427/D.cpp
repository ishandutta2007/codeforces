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

int n;
int c[60];

V<int> gen(V<bool> f) {
    f[0] = true;
    V<int> pos;

    rep(i, n) {
        if (f[i]) {
            pos.pb(i);
        }
    }
    pos.pb(n);
    V<int> res;
    rep(i, SZ(pos) - 1) { res.pb(pos[i + 1] - pos[i]); }
    return res;
}

void doit(V<int> vs) {
    int s = 0;
    for (int v : vs) s += v;
    assert(s == n);
    s = 0;
    VV<int> bl;
    for (int v : vs) {
        V<int> vec;
        rep(i, v) { vec.pb(c[s++]); }
        bl.pb(vec);
    }
    reverse(ALL(bl));
    s = 0;
    for (auto& vec : bl) {
        for (auto v : vec) {
            c[s++] = v;
        }
    }
    // rep(i, n) cerr << c[i] << ' ';
    // cerr << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, n) cin >> c[i], --c[i];
    VV<int> ope;

    for (int i = 1; i <= n - 1; ++i) {
        int f = 0;
        rep(p, n) if (c[p] < i) {
            f = p;
            break;
        }
        int d = 0;
        rep(p, n) if (c[p] == i) { d = p; }
        bool rev = 0;
        if (c[f] != 0) {
            rev = 1;
        }
        V<bool> use(n);
        if (!rev && f < d) {
            for (int j = f; j <= f + i; ++j) use[j] = true;
            if (d + 1 < n) use[d + 1] = true;
        } else if (!rev) {
            use[f] = use[d] = true;
            if (f + i < n) use[f + i] = true;
        } else if (f < d) {
            use[f] = use[d] = true;
            if (d + 1 < n) use[d + 1] = true;
        } else {
            for (int j = f; j < f + i; ++j) use[j] = true;
            if (f + i < n) use[f + i] = true;
            use[d] = true;
        }
        auto res = gen(use);
        ope.pb(res);

        doit(ope.back());
    }

    if (c[0]) {
        V<bool> use(n);
        rep(i, n) use[i] = true;
        auto res = gen(use);
        ope.pb(res);
        doit(ope.back());
    }

    cout << ope.size() << endl;
    rep(i, SZ(ope)) {
        int k = ope[i].size();
        cout << k;
        for (int v : ope[i]) cout << ' ' << v;
        cout << endl;
    }

    return 0;
}