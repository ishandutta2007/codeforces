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

const ll INF = TEN(16);
using pll = pair<ll, ll>;
using p3 = pair<pll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    V<ll> h(n), a(n);
    rep(i, n) cin >> h[i] >> a[i];

    auto ok = [&](ll x) {
        V<int> la(n, -1);
        V<ll> cur(n, x);
        debug(x);

        priority_queue<pll, V<pll>, greater<pll>> que;
        priority_queue<pll> need;

        rep(i, n) {
            ll md = x / a[i] + 1;
            if (md <= m) {
                que.emplace(md, i);
            } else if (x - m * a[i] < h[i]) {
                need.emplace(h[i] - (x - m * a[i]), i);
            }
        }

        rep(i, m) {
            int rem = k;

            while (rem > 0 && que.size()) {
                auto pr = que.top();
                que.pop();
                if (pr.fi - 1 <= i) return false;
                int id = pr.se;
                ll v = cur[id] + p - (i - la[id]) * a[id];
                rem--;
                la[id] = i;
                cur[id] = v;
                if (v < 0) return false;
                ll md = i + 1 + v / a[id] + 1;
                debug(i, pr, md);
                if (md <= m)
                    que.emplace(md, id);
                else {
                    ll sh = h[id] - (v - (m - i - 1) * a[id]);
                    if (sh > 0) need.emplace(sh, id);
                }
            }
            while (rem > 0 && need.size()) {
                auto pr = need.top();
                need.pop();
                int id = pr.se;
                rem--;
                if (pr.fi - p > 0) {
                    need.emplace(pr.fi - p, id);
                }
            }
        }

        return que.size() == 0 && need.size() == 0;
    };

    ll lo = 0, hi = INF;
    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        if (ok(m)) {
            hi = m;
        } else {
            lo = m;
        }
    }
    cout << hi << endl;

    return 0;
}