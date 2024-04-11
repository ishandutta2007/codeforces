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
    int minright;
    int goodcnt;
    bool lazy;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->minright = 1000000; st->goodcnt = 0;
    st->lazy = false;
    if (l < r) {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
    } else {
        st->lchild = st->rchild = NULL;
    }
    return st;
}

void pushdown(Segtree* st)
{
    if (st->lazy) {
        st->lazy = false;
        st->goodcnt = st->r - st->l + 1;
        if (st->l < st->r) st->lchild->lazy = st->rchild->lazy = true;
    }
}

void markgood(Segtree* st, int l, int r)
{
    pushdown(st);
    if (st->r < l || r < st->l) return;
    if (l <= st->l && st->r <= r) {
        st->lazy = true; pushdown(st);
    } else {
        markgood(st->lchild, l, r);
        markgood(st->rchild, l, r);
        st->goodcnt = st->lchild->goodcnt + st->rchild->goodcnt;
    }
}

int findnongood(Segtree* st, int last)
{
    pushdown(st);
    if (st->l >= last) return -1;
    if (st->goodcnt == st->r - st->l + 1) return -1;
    if (st->l == st->r) return st->l;
    if (last <= (st->l + st->r) / 2) {
        return findnongood(st->lchild, last);
    }
    if (last <= st->r) {
        int res = findnongood(st->rchild, last);
        if (res == -1) {
            return findnongood(st->lchild, last);
        } else {
            return res;
        }
    }
    int res2 = findnongood(st->rchild, last);
    if (res2 != -1) {
        return res2;
    } else {
        return findnongood(st->lchild, last);
    }
}

int querygood(Segtree* st, int l, int r)
{
    pushdown(st);
    if (r < l) return 0;
    if (st->r < l || r < st->l) return 0;
    if (l <= st->l && st->r <= r) return st->goodcnt;
    return querygood(st->lchild, l, r) + querygood(st->rchild, l, r);
}

void setr(Segtree* st, int pos, int val)
{
    if (st->l == st->r) {
        st->minright = min(st->minright, val);
    } else {
        if (pos <= (st->l + st->r) / 2) {
            setr(st->lchild, pos, val);
        } else {
            setr(st->rchild, pos, val);
        }
        st->minright = min(st->lchild->minright, st->rchild->minright);
    }
}

int queryr(Segtree* st, int l, int r)
{
    if (r < l) return 1000000;
    if (st->r < l || r < st->l) return 1000000;
    if (l <= st->l && st->r <= r) return st->minright;
    return min(queryr(st->lchild, l, r), queryr(st->rchild, l, r));
}

int n, q;
Segtree* root;

int main()
{
    scanf("%d%d", &n, &q);
    root = build(0, n);
    for (int i = 1; i <= q; i++) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            if (x == 0) {
                markgood(root, l, r);
            } else {
                setr(root, l, r);
            }
        } else {
            int pos; scanf("%d", &pos);
            if (querygood(root, pos, pos) == 1) {
                printf("NO\n"); continue;
            }
            int pre = findnongood(root, pos);
            int nxt = queryr(root, pre + 1, pos);
            //printf("! %d %d\n", pre, nxt);
            if (nxt > n) {
                printf("N/A\n"); continue;
            }
            nxt = min(nxt, n);
            if (querygood(root, pos + 1, nxt) == nxt - pos) {
                printf("YES\n");
            } else {
                printf("N/A\n");
            }
        }
    }
    return 0;
}