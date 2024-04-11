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

void ng() {
    puts("-1");
    exit(0);
}

const double INF = 1e9;
const double EPS = 1e-7;

int main() {
    int n;
    int lx, rx, ly, ry;
    scanf("%d %d %d %d %d", &n, &lx, &ly, &rx, &ry);
    V<pair<double, double>> rng;

    auto calc = [&](ll l, ll r, ll v) {
        if (v == 0) {
            return mp(-INF, INF);
        }
        double tl = (double)l + EPS, tr = (double)r - EPS;
        if (v < 0) {
            swap(l, r);
            tl = (double)l - EPS, tr = (double)r + EPS;
        }
        debug(tl, tr);
        return mp(tl / v, tr / v);
    };

    if (lx == rx || ly == ry) {
        ng();
    }

    rep(i, n) {
        int a, b, vx, vy;
        scanf("%d %d %d %d", &a, &b, &vx, &vy);
        if (vx == 0 && (a <= lx || rx <= a)) {
            ng();
        }
        if (vy == 0 && (b <= ly || ry <= b)) {
            ng();
        }

        auto p = calc(lx - a, rx - a, vx);
        auto q = calc(ly - b, ry - b, vy);
        rng.eb(max(p.fi, q.fi), min(p.se, q.se));
    }
    //  debug(rng);
    double ans = 0.0;
    for (auto p : rng) {
        chmax(ans, p.fi);
    }
    for (auto p : rng) {
        if (ans > p.se) {
            ng();
        }
    }
    printf("%.9f\n", ans);

    return 0;
}