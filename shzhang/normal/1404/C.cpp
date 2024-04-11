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
    int minv;
    int tag;
    int rcnt;
};

void pushdown(Segtree* st)
{
    if (!st->tag) return;
    st->minv -= st->tag;
    if (st->lchild) {
        st->lchild->tag += st->tag;
        st->rchild->tag += st->tag;
    }
    st->tag = 0;
}

int n, q;
int seq[300005];

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->tag = 0;
    st->rcnt = 0;
    st->l = l; st->r = r;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->minv = seq[l];
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        st->minv = min(st->lchild->minv, st->rchild->minv);
    }
    return st;
}

void find_zeros(Segtree* st, int l, int r, priority_queue<int>& vals)
{
    pushdown(st);
    if (st->r < l || r < st->l) return;
    if (!st->lchild) {
        if (st->minv <= 0) vals.push(st->l);
        return;
    }
    pushdown(st->lchild);
    pushdown(st->rchild);
    if (st->lchild->minv <= 0) find_zeros(st->lchild, l, r, vals);
    if (st->rchild->minv <= 0) find_zeros(st->rchild, l, r, vals);
}

void modify(Segtree* st, int l, int r)
{
    pushdown(st);
    if (l <= st->l && st->r <= r) {
        st->tag++; return;
    }
    if (st->r < l || r < st->l) return;
    modify(st->lchild, l, r);
    modify(st->rchild, l, r);
    pushdown(st->lchild);
    pushdown(st->rchild);
    st->minv = min(st->lchild->minv, st->rchild->minv);
}

void modifyval(Segtree* st, int pos, int val)
{
    pushdown(st);
    if (!st->lchild) {
        st->minv = val; return;
    }
    if (pos > (st->l + st->r) / 2) {
        modifyval(st->rchild, pos, val);
    } else {
        modifyval(st->lchild, pos, val);
    }
    st->minv = min(st->lchild->minv, st->rchild->minv);
}

void incr(Segtree* st, int pos)
{
    //printf("inc %d\n", pos);
    st->rcnt++;
    if (!st->lchild) return;
    if (pos > (st->l + st->r) / 2) {
        incr(st->rchild, pos);
    } else {
        incr(st->lchild, pos);
    }
}

int query_intv(Segtree* st, int l, int r)
{
    //printf("%d %d\n", l, r);
    if (l <= st->l && st->r <= r) {
        return st->rcnt;
    }
    if (st->r < l || r < st->l) return 0;
    return query_intv(st->lchild, l, r) + query_intv(st->rchild, l, r);
}

Segtree* root;

struct Query {
    int x, y, id;
};

vector<Query> queries[300005];
int answer[300005];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", seq + i);
    for (int i = 1; i <= n; i++) {
        seq[i] = i - seq[i];
        if (seq[i] < 0) seq[i] = 10000000;
        //rintf("%d ", seq[i]);
    }
    root = build(1, n);
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        Query qry; qry.x = x;
        qry.y = y;
        qry.id = i;
        queries[x].push_back(qry);
    }
    for (int i = n; i >= 1; i--) {
        if (seq[i] == 0) {
            priority_queue<int> que;
            que.push(i);
            while (!que.empty()) {
                int val = que.top(); que.pop();
                //printf("work %d\n", val);
                if (val != n) {
                    modify(root, val + 1, n);
                    find_zeros(root, val + 1, n, que);
                }
                modifyval(root, val, 10000000);
                incr(root, val);
            }
        }
        for (int j = 0; j < queries[i-1].size(); j++) {
            Query qry = queries[i-1][j];
            answer[qry.id] = query_intv(root, i, n - qry.y);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}