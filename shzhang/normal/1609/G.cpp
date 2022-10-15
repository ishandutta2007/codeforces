#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

struct Segtree {
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
    ll val; // NONZERO FOR RIGHT CHILDREN ONLY
    ll sum, lsum, lazy;
};

int n, m, q;
ll a[105];
ll bi[100005];

Segtree* root;

Segtree* build(int l, int r, ll subv)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->val = bi[l] - subv;
    st->lazy = 0;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->lsum = st->sum = bi[l];
    } else {
        st->lchild = build(l, (l + r) / 2, bi[l]);
        st->rchild = build((l + r) / 2 + 1, r, bi[l]);
        st->sum = st->lchild->sum + st->rchild->sum;
        st->lsum = st->lchild->lsum + st->rchild->lsum +
            st->lchild->sum * (ll)(r - (l + r) / 2);
    }
    return st;
}

void pushdown(Segtree* st)
{
    ll off = st->lazy;
    if (st->l < st->r) {
        st->lchild->lazy += off;
        st->rchild->lazy += off;
    }
    st->lazy = 0;
    ll siz = (st->r - st->l + 1);
    st->sum += siz * off;
    st->lsum += ((siz * (siz + 1)) / 2LL) * off;
}

void modify(Segtree* st, int l, ll off)
{
    //debug("modify begin %d %d %d\n", st->l, st->r, l);
    pushdown(st);
    if (st->r < l) return;
    if (l <= st->l) {
        st->lazy += off;
        st->val += off;
        pushdown(st);
    } else {
        modify(st->lchild, l, off);
        modify(st->rchild, l, off);
        st->sum = st->lchild->sum + st->rchild->sum;
        st->lsum = st->lchild->lsum + st->rchild->lsum +
            st->lchild->sum * (ll)(st->r - (st->l + st->r) / 2);
    }
    //debug("modify end");
}

int last[105];
ll psum[105];

void search(int idx, ll bound)
{
    Segtree* cur = root;
    ll cursum = 0;
    //debug("here4 %d %d", cur->l, cur->r);
    ll curval = 0;
    while (cur->l < cur->r) {
        pushdown(cur);
        pushdown(cur->lchild);
        //debug("! %lld", cur->rchild->val);
        if (curval + cur->rchild->val <= bound) {
            //debug("!! %lld", cur->lchild->sum);
            cursum += cur->lchild->sum;
            curval += cur->rchild->val;
            cur = cur->rchild;
        } else {
            cur = cur->lchild;
        }
    }
    pushdown(cur);
    last[idx] = cur->l;
    psum[idx] = cursum + cur->sum;
}

ll b1;

ll solve()
{
    a[n+1] = 1000000000000000000LL;
    for (int i = 2; i <= n + 1; i++) {
        search(i, a[i]);
        //debug("%lld %d %lld", a[i], last[i], psum[i]);
        //debug("here3");
    }
    //debug("!!!! %lld\n", root->sum);
    ll ans = (ll)(n + m - 1) * (a[1] + b1) + root->lsum;
    //debug("%lld %lld %lld %lld", ans, a[1], b1, root->lsum);
    for (int i = 2; i <= n + 1; i++) {
        //printf("%lld %d %lld\n", (ll)(n + m - i + 1 - last[i]), i, a[i]);
        ans += (n + m - i + 1 - last[i]) * a[i];
        if (i <= n) ans += psum[i];
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = n; i >= 1; i--) a[i] -= a[i-1];
    for (int i = 1; i <= m; i++) scanf("%lld", bi + i);
    b1 = bi[1];
    for (int i = m; i >= 1; i--) bi[i] -= bi[i-1];
    bi[1] = 0;
    root = build(0, m, 0);
    for (int qr = 1; qr <= q; qr++) {
        int type; int k; ll d;
        //debug("here");
        scanf("%d%d%lld", &type, &k, &d);
        if (type == 1) {
            for (int i = n - k + 1; i <= n; i++) a[i] += d;
        } else {
            if (k == m) {
                k--; b1 += d;
            }
            modify(root, m - k + 1, d);
        }
        //debug("here2");
        printf("%lld\n", solve());
    }
    return 0;
}