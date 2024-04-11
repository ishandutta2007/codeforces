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

struct Triple {
    int minx, miny, minpr;
};

struct Segtree {
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
    Triple tri;
    int lazyx, lazyy;
};

int iasum[100005], ibsum[100005], icsum[100005];

Triple merge(const Triple& t1, const Triple& t2)
{
    Triple ans;
    ans.minx = min(t1.minx, t2.minx);
    ans.miny = min(t1.miny, t2.miny);
    ans.minpr = min(min(t1.minpr, t2.minpr), t1.minx + t2.miny);
    return ans;
}

void pushdown(Segtree* st)
{
    if (st->l != st->r) {
        st->lchild->lazyx += st->lazyx;
        st->lchild->lazyy += st->lazyy;
        st->rchild->lazyx += st->lazyx;
        st->rchild->lazyy += st->lazyy;
    }
    st->tri.minx += st->lazyx;
    st->tri.miny += st->lazyy;
    st->tri.minpr += st->lazyx + st->lazyy;
    st->lazyx = st->lazyy = 0;
}

void modify(Segtree* st, int l, int r, int xoff, int yoff)
{
    pushdown(st);
    if (st->r < l || r < st->l) return;
    if (l <= st->l && st->r <= r) {
        st->lazyx = xoff; st->lazyy = yoff; pushdown(st);
    } else {
        modify(st->lchild, l, r, xoff, yoff);
        modify(st->rchild, l, r, xoff, yoff);
        st->tri = merge(st->lchild->tri, st->rchild->tri);
    }
}

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->lazyx = st->lazyy = 0;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->tri.minx = iasum[l] - ibsum[l];
        st->tri.miny = ibsum[l] - icsum[l];
        st->tri.minpr = st->tri.minx + st->tri.miny;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        st->tri = merge(st->lchild->tri, st->rchild->tri);
    }
    return st;
}

Segtree* root;

int n, q;
char s[100005];

int getxoff(char c)
{
    if (c == 'a') return 1;
    if (c == 'b') return -1;
    return 0;
}

int getyoff(char c)
{
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return -1;
}

int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        iasum[i] = iasum[i-1] + (s[i] == 'a' ? 1 : 0);
        ibsum[i] = ibsum[i-1] + (s[i] == 'b' ? 1 : 0);
        icsum[i] = icsum[i-1] + (s[i] == 'c' ? 1 : 0);
    }
    int ccnt = icsum[n];
    root = build(0, n);
    for (int qr = 1; qr <= q; qr++) {
        int idx; char c[5];
        scanf("%d%s", &idx, c);
        int xoff = -getxoff(s[idx]);
        int yoff = -getyoff(s[idx]);
        if (s[idx] == 'c') ccnt--;
        s[idx] = c[0];
        if (s[idx] == 'c') ccnt++;
        xoff += getxoff(s[idx]);
        yoff += getyoff(s[idx]);
        modify(root, idx, n, xoff, yoff);
        printf("%d\n", root->tri.minpr + ccnt);
    }
    //printf("%d", root->tri.minpr);
    return 0;
}