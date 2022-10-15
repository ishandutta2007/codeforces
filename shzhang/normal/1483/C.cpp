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

#define INF 1000000000000000000LL

struct Segtree {
    int l, r;
    ll maxv;
    Segtree* lchild; Segtree* rchild;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->maxv = 0;
    if (st->l == st->r) {
        st->lchild = st->rchild = NULL;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
    }
    return st;
}

Segtree* root;

ll query(Segtree* st, int l, int r)
{
    if (r < st->l || st->r < l) return -INF;
    if (l <= st->l && st->r <= r) return st->maxv;
    return max(query(st->lchild, l, r), query(st->rchild, l, r));
}

void modify(Segtree* st, int pos, ll val)
{
    if (st->l == st->r) {
        st->maxv = val;
    } else {
        if (pos <= (st->l + st->r) / 2) {
            modify(st->lchild, pos, val);
        } else {
            modify(st->rchild, pos, val);
        }
        st->maxv = max(st->lchild->maxv, st->rchild->maxv);
    }
}

int n;
int h[300005];
ll b[300005];
ll f[300005];
int stk[300005];
ll maxval[300005];
int stktop = 1;

int main()
{
    scanf("%d", &n);
    root = build(0, n);

    for (int i = 1; i <= n; i++) scanf("%d", h + i);
    for (int i = 1; i <= n; i++) scanf("%lld", b + i);
    multiset<ll> values;
    for (int i = 1; i <= n; i++) {
        while (h[stk[stktop - 1]] > h[i]) {
            stktop--; values.erase(values.find(-maxval[stktop]));
        }
        stk[stktop] = i;
        maxval[stktop] = query(root, stk[stktop - 1], stk[stktop] - 1) + b[i];
        values.insert(-maxval[stktop]);
        stktop++;
        f[i] = -(*values.begin());
        modify(root, i, f[i]);
    }
    printf("%lld", f[n]);
    return 0;
}