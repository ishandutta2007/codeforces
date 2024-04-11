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

static inline ll updiv(ll a, ll b)
{
    return (a % b == 0) ? a / b : a / b + 1;
}

struct Segtree {
    Segtree* lchild;
    Segtree* rchild;
    int l, r;
    int minv;
    int lazy;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->minv = 0; st->lazy = 0;
    if (l == r) {
        st->lchild = st->rchild = NULL;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
    }
    return st;
}

void pushdown(Segtree* st)
{
    st->minv += st->lazy;
    if (st->l < st->r) {
        st->lchild->lazy += st->lazy;
        st->rchild->lazy += st->lazy;
    }
    st->lazy = 0;
}

void modify(Segtree* st, int l, int r, int amt)
{
    pushdown(st);
    if (r < st->l || st->r < l) return;
    if (l <= st->l && st->r <= r) {
        st->lazy += amt; pushdown(st); return;
    }
    modify(st->lchild, l, r, amt);
    modify(st->rchild, l, r, amt);
    st->minv = min(st->lchild->minv, st->rchild->minv);
}

Segtree* root;

int a[100005];
vector<int> group[100005];
ll tot[100005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) {
        group[i].clear(); tot[i] = 0;
        int k; scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int val; scanf("%d", &val);
            group[i].push_back(val);
            tot[i] += (ll)val;
        }
    }
    for (int i = 1; i <= n; i++) {
        modify(root, 1, a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        modify(root, 1, updiv(tot[i], group[i].size()), -1);
    }
    for (int i = 1; i <= m; i++) {
        int oldavg = updiv(tot[i], group[i].size());
        modify(root, 1, oldavg, 1);
        for (int j = 0; j < group[i].size(); j++) {
            int newavg = updiv(tot[i] - (ll)group[i][j],
                group[i].size() - 1);
            modify(root, 1, newavg, -1);
            printf("%d", root->minv >= 0 ? 1 : 0);
            modify(root, 1, newavg, 1);
        }
        modify(root, 1, oldavg, -1);
    }
    for (int i = 1; i <= m; i++) {
        modify(root, 1, updiv(tot[i], group[i].size()), 1);
    }
    for (int i = 1; i <= n; i++) {
        modify(root, 1, a[i], -1);
    }
    printf("\n");
}

int main()
{
    root = build(1, 100000);
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}