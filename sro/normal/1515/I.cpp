#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1 << 18, mxlog = 18;

struct CF1515I {
    ll a, w, v;
    int id;
    bool operator < (const CF1515I &x) const {
        return mak(-v, w) < mak(-x.v, x.w);
    }
} s[maxn];

int n, q;

struct SegtreeH {
    ll ws[maxn << 1], vs[maxn << 1];
    void inline add(int a, int x) {
        int p = a;
        for (a += maxn; a; a >>= 1) {
            ws[a] += s[p].w * x;
            vs[a] += s[p].v * x;
        }
    }
    ll inline sumw(int l, int r) {
        ll res = 0;
        for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += ws[l++];
            if (r & 1) res += ws[--r];
        }
        return res;
    }
    int inline find(int l, int r, ll &val, ll &res, int now = 1, int nl = 0, int nr = maxn - 1) {
        if (nl > r || nr < l || l > r) return -1;
        if (nl >= l && nr <= r && ws[now] <= val) {
            val -= ws[now]; res += vs[now];
            return -1;
        }
        if (nl == nr) return nl;
        int m = (nl + nr) >> 1;
        int v = find(l, r, val, res, now << 1, nl, m);
        if (!~v) v = find(l, r, val, res, now << 1 | 1, m + 1, nr);
        return v;
    }
} s1[mxlog + 1];

struct SegtreeHe {
    ll mn[maxn << 1], tg[maxn << 1];
    void inline init() { memset(mn, Inf, sizeof(mn)); }
    void inline push(int a, ll x) { mn[a] += x; tg[a] += x; }
    void inline pd(int now) {
        if (tg[now]) {
            push(now << 1, tg[now]);
            push(now << 1 | 1, tg[now]);
            tg[now] = 0;
        }
    }
    void inline pu(int now) { mn[now] = min(mn[now << 1], mn[now << 1 | 1]); }
    void inline add(int l, int r, ll x) {
        l += maxn; r += maxn + 1;
        int cl = l, cr = r;
        range(i, mxlog, 1, -1) {
            if ((l >> i << i) != l) pd(l >> i);
            if ((r >> i << i) != r) pd(r >> i);
        }
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) push(l++, x);
            if (r & 1) push(--r, x);
        }
        l = cl; r = cr;
        cont(i, mxlog) {
            if ((l >> i << i) != l) pu(l >> i);
            if ((r >> i << i) != r) pu(r >> i);
        }
    }
    void inline change(int a, ll x) {
        a += maxn;
        range(i, mxlog, 1, -1) pd(a >> i);
        mn[a] = x;
        cont(i, mxlog) pu(a >> i);
    }
    int inline find(int l, int r, ll val, int now = 1, int nl = 0, int nr = maxn - 1) {
        if (nl > r || nr < l || l > r) return -1;
        if (nl >= l && nr <= r && mn[now] > val) return -1;
        if (nl == nr) return nl;
        int m = (nl + nr) >> 1; pd(now);
        int v = find(l, r, val, now << 1, nl, m);
        if (!~v) v = find(l, r, val, now << 1 | 1, m + 1, nr);
        return v;
    }
} s2[mxlog + 1];

int tp[maxn], dy[maxn];

void inline init(int lg) {
    s2[lg].init();
    loop(i, n) if (s[i].w < (1 << lg)) s1[lg].add(i, s[i].a);
    loop(i, n) {
        if (tp[i] != lg || !s[i].a) s2[lg].change(i, INF);
        else s2[lg].change(i, s[i].w + s1[lg].sumw(0, i - 1));
    }
}

void inline modify(int i, ll x) {
    loop(lg, mxlog + 1) if (s[i].w < (1 << lg)) {
        s1[lg].add(i, x);
        s2[lg].add(i, maxn - 1, x * s[i].w);
    }
    int lg = tp[i];
    if (!s[i].a) s2[lg].change(i, s[i].w + s1[lg].sumw(0, i - 1));
    s[i].a += x;
    if (!s[i].a) s2[lg].change(i, INF);
}

ll query(ll c) {
    ll ans = 0;
    int pos = 0;
    range(lg, mxlog, 0, -1) if (c >= (1 << lg)) {
        ll wc = c - (1 << lg);
        int rpos = s2[lg].find(pos, maxn - 1, c + s1[lg].sumw(0, pos - 1));
        if (!~rpos) rpos = maxn;
        pos = s1[lg].find(pos, rpos - 1, wc, ans);
        if (!~pos) pos = rpos;
        c = wc + (1 << lg);
        if (pos < n) {
            ll d = min(s[pos].a, c / s[pos].w);
            ans += d * s[pos].v;
            c -= d * s[pos++].w;
        }
        if (pos >= n) break;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    loop(i, n) scanf("%lld%lld%lld", &s[i].a, &s[i].w, &s[i].v), s[i].id = i + 1;
    sort(s, s + n);
    loop(i, n) {
        while (s[i].w >= (1 << (tp[i] + 1))) ++tp[i];
        dy[s[i].id] = i;
    }
    loop(i, mxlog + 1) init(i);
    while (q--) {
        int tp; scanf("%d", &tp);
        if (tp <= 2) {
            int k, d; scanf("%d%d", &k, &d);
            d = dy[d]; if (tp == 2) k = -k;
            modify(d, k);
        }
        else {
            ll c; scanf("%lld", &c);
            printf("%lld\n", query(c));
        }
    }
    return 0;
}