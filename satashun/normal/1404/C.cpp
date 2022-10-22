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

int sz;
const int INF = TEN(9);

struct starry_sky_tree {
    int all[1 << 20], ma[1 << 20], piv[1 << 20];

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rep(i, sz * 2) {
            all[i] = 0;
            ma[i] = 0;
            piv[i] = 0;
        }
        for (int i = sz - 1; i < sz * 2 - 1; ++i) {
            piv[i] = i - (sz - 1);
        }
        for (int i = sz - 1 + n; i < sz * 2 - 1; ++i) {
            ma[i] = INF;
        }
        for (int i = sz - 2; i >= 0; --i) {
            ma[i] = min(ma[i * 2 + 1], ma[i * 2 + 2]);
            if (ma[i] == ma[i * 2 + 2]) {
                piv[i] = piv[i * 2 + 2];
            } else if (ma[i] == ma[i * 2 + 1]) {
                piv[i] = piv[i * 2 + 1];
            }
        }
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            all[k] += x;
            return;
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] =
            min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
        if (ma[k] == ma[k * 2 + 2] + all[k * 2 + 2]) {
            piv[k] = piv[k * 2 + 2];
        } else if (ma[k] == ma[k * 2 + 1] + all[k * 2 + 1]) {
            piv[k] = piv[k * 2 + 1];
        }
    }

    pii get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return mp(INF, 0);
        if (a <= l && r <= b) {
            return mp(ma[k] + all[k], piv[k]);
        }

        pii lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        pii rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        int pos = -1;
        int mini = min(lc.fi, rc.fi);
        if (mini == rc.fi) {
            pos = rc.se;
        } else if (mini == lc.fi) {
            pos = lc.se;
        }
        return mp(mini + all[k], pos);
    }
} seg;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    V<int> a(n);
    rep(i, n) cin >> a[i], --a[i];
    rep(i, n) a[i] = i - a[i];
    debug(a);

    /*
        rep(i, q) {
            int x, y;
            cin >> x >> y;

            V<int> b = a;
            int cnt = 0;
            int ans = 0;
            rep(j, n) {
                if (j >= x && j + y < n) {
                    if (b[j] >= 0 && b[j] <= ans) {
                        ans++;
                    }
                }
            }
            cout << ans << endl;
        }*/

    VV<pii> qr(n);
    BIT<int> T(n);
    starry_sky_tree seg;
    seg.init(n);

    rep(i, q) {
        int x, y;
        cin >> x >> y;
        qr[x].eb(y, i);
    }

    V<int> ans(q);

    per(l, n) {
        int v = a[l] >= 0 ? a[l] : INF;
        seg.add(l, l + 1, v, 0, 0, sz);
        while (true) {
            pii res = seg.get(l, n, 0, 0, sz);
            if (res.fi == 0) {
                T.add(res.se, 1);
                seg.add(res.se + 1, n, -1, 0, 0, sz);
                seg.add(res.se, res.se + 1, INF, 0, 0, sz);
            } else {
                break;
            }
        }
        for (auto p : qr[l]) {
            ans[p.se] = T.sum(l, n - p.fi);
        }
    }
    rep(i, q) cout << ans[i] << '\n';

    return 0;
}