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
#define ALL(c) (c).begin(), (c).end()

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

template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n = 0) : n(_n), bit(n + 1) {}

    // sum of [0, i), 0 <= i <= n
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // 0 <= i < n
    void add(int i, T x) {
        ++i;
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    //[l, r) 0 <= l < r < n
    T sum(int l, int r) { return sum(r) - sum(l); }
};

const int MX = 200010;

int num[MX][4];

struct Event {
    int x, tp, ly, ry, id;
    Event() {}
    Event(int tp, int x, int ly, int ry, int id)
        : x(x), tp(tp), ly(ly), ry(ry), id(id) {}
    bool operator<(const Event& a) {
        if (x != a.x) return x < a.x;
        if (tp != a.tp) return tp < a.tp;
        return false;
    }
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    V<int> p(n);
    rep(i, n) scanf("%d", &p[i]), --p[i];

    V<Event> vec;

    rep(i, n) { vec.eb(0, i, p[i], -1, -1); }
    V<pair<pii, pii>> rect(q);

    rep(i, q) {
        int l, d, r, u;
        scanf("%d%d%d%d", &l, &d, &r, &u);
        --l, --d;
        rect[i] = mp(mp(l, d), mp(r, u));
        vec.eb(-1, l, d, u, i);
        vec.eb(1, r - 1, d, u, i);
    }
    sort(ALL(vec));

    BIT<int> T(n + 10);

    for (auto e : vec) {
        if (e.tp == -1) {
            num[e.id][0] = T.sum(e.ly);
            num[e.id][1] = T.sum(e.ry, n + 10);
        } else if (e.tp == 1) {
            num[e.id][2] = T.sum(e.ly);
            num[e.id][3] = T.sum(e.ry, n + 10);
        } else {
            T.add(p[e.x], 1);
        }
    }

    rep(i, q) { debug(i, num[i][0], num[i][1], num[i][2], num[i][3]); }

    rep(i, q) {
        ll a, b, c, d;
        tie(a, b) = rect[i].fi, tie(c, d) = rect[i].se;
        ll ans = (ll)n * (n - 1) / 2 - a * (a - 1) / 2 - b * (b - 1) / 2 -
                 (n - c) * (n - c - 1) / 2 - (n - d) * (n - d - 1) / 2;
        ll p = num[i][0];
        ll q = num[i][1];
        ll r = b - num[i][2];
        ll s = n - d - num[i][3];
        ans += p * (p - 1) / 2 + q * (q - 1) / 2 + r * (r - 1) / 2 +
               s * (s - 1) / 2;
        printf("%lld\n", ans);
        debug(i, ans);
    }

    return 0;
}