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

const int maxn = 1 << 17;

struct Segbeats {
    int mx[maxn << 1], nx[maxn << 1], mxs[maxn << 1];
    ll sm[maxn << 1];
    void inline init() {
        memset(mx, Inf, sizeof(mx));
    }
    void inline push(int now, int x) {
        sm[now] -= 1ll * (mx[now] - x) * mxs[now];
        mx[now] = x;
    }
    void inline pd(int now) {
        if (mx[now] < mx[now << 1]) push(now << 1, mx[now]);
        if (mx[now] < mx[now << 1 | 1]) push(now << 1 | 1, mx[now]);
    }
    void inline pu(int now) {
        sm[now] = sm[now << 1] + sm[now << 1 | 1];
        if (mx[now << 1] > mx[now << 1 | 1]) {
            mx[now] = mx[now << 1];
            nx[now] = max(nx[now << 1], mx[now << 1 | 1]);
            mxs[now] = mxs[now << 1];
        }
        else if (mx[now << 1 | 1] > mx[now << 1]) {
            mx[now] = mx[now << 1 | 1];
            nx[now] = max(nx[now << 1 | 1], mx[now << 1]);
            mxs[now] = mxs[now << 1 | 1];
        }
        else {
            mx[now] = mx[now << 1];
            nx[now] = max(nx[now << 1], nx[now << 1 | 1]);
            mxs[now] = mxs[now << 1] + mxs[now << 1 | 1];
        }
    }
    void inline chmin(int l, int r, int x, int now = 1, int nl = 0, int nr = maxn - 1) {
        if (nl >= l && nr <= r) {
            if (mx[now] < x) return;
            if (nx[now] < x) return push(now, x);
        }
        if (nl > r || nr < l) return;
        pd(now); int m = (nl + nr) >> 1;
        chmin(l, r, x, now << 1, nl, m);
        chmin(l, r, x, now << 1 | 1, m + 1, nr);
        pu(now);
    }
    ll inline query(int l, int r, int now = 1, int nl = 0, int nr = maxn - 1) {
        if (nl >= l && nr <= r) return sm[now];
        if (nl > r || nr < l) return 0;
        pd(now); int m = (nl + nr) >> 1;
        return query(l, r, now << 1, nl, m) + query(l, r, now << 1 | 1, m + 1, nr);
    }
    void inline activate(int to, int now = 1, int nl = 0, int nr = maxn - 1) {
        if (nl == nr) return (void)(mxs[now] = 1, sm[now] = mx[now]);
        pd(now); int m = (nl + nr) >> 1;
        if (m >= to) activate(to, now << 1, nl, m);
        else activate(to, now << 1 | 1, m + 1, nr);
        pu(now);
    }
} sgz, sgf;

set<int> un[4];

void inline moveto(int l, int r, int fr, int to) {
    auto it = un[fr].lower_bound(l);
    while (it != un[fr].end() && *it <= r) {
        if (!to) sgf.activate(*it), sgz.activate(*it);
        un[to].insert(*it);
        it = un[fr].erase(it);
    }
}

int main() {
    int q; scanf("%d", &q);
    loop(i, maxn) un[3].insert(i);
    sgz.init(); sgf.init();
    while (q--) {
        int mode; scanf("%d", &mode);
        if (mode == 1) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k); --r;
            int sb = 0;
            if (k < 0) k = -k, sb = 1;
            if (sb) {
                sgf.chmin(l, r, k);
                moveto(l, r, 3, 1);
                moveto(l, r, 2, 0);
            }
            else {
                sgz.chmin(l, r, k);
                moveto(l, r, 3, 2);
                moveto(l, r, 1, 0);
            }
        }
        else {
            int l, r; scanf("%d%d", &l, &r); --r;
            printf("%lld\n", sgz.query(l, r) + sgf.query(l, r));
        }
    }
    return 0;
}