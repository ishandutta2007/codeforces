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

int initv[200005];

struct Segtree {
    int l, r, minv, lazy;
    Segtree* lchild;
    Segtree* rchild;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r; st->lazy = 0;
    if (l == r) {
        st->minv = initv[l];
        st->lchild = st->rchild = NULL;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        st->minv = max(st->lchild->minv, st->rchild->minv);
    }
    return st;
}

void pushdown(Segtree* st)
{
    st->minv += st->lazy;
    if (st->l != st->r) {
        st->lchild->lazy += st->lazy;
        st->rchild->lazy += st->lazy;
    }
    st->lazy = 0;
}

int findmin(Segtree* st)
{
    if (st->l == st->r) return st->l;
    pushdown(st);
    pushdown(st->lchild);
    pushdown(st->rchild);
    //debug("here %d %d %d %d %d", st->l, st->r, st->minv, st->lchild->minv, st->rchild->minv);
    if (st->minv == st->lchild->minv) {
        return findmin(st->lchild);
    } else {
        return findmin(st->rchild);
    }
}

Segtree* root;

void modify(Segtree* st, int l, int r, int val)
{
    /*if (st == root) {
        printf("%d %d %d\n", l, r, val);
    }*/
    pushdown(st);
    if (st->r < l || r < st->l) return;
    if (l <= st->l && st->r <= r) {
        st->lazy += val; pushdown(st);
    } else {
        modify(st->lchild, l, r, val);
        modify(st->rchild, l, r, val);
        st->minv = max(st->lchild->minv, st->rchild->minv);
    }
}

int n, k;
vector<int> graph[200005];
int dfsorder[200005][2];
int dfs2node[200005];
int dfsnxt = 1;
int parent[200005];

void dfs(int node, int prt)
{
    dfsorder[node][0] = dfsnxt++;
    initv[dfsorder[node][0]] = initv[dfsorder[prt][0]] + 1;
    parent[node] = prt;
    dfs2node[dfsorder[node][0]] = node;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (child == prt) continue;
        dfs(child, node);
    }
    dfsorder[node][1] = dfsnxt - 1;
}

bool taken[200005];

void output_st(Segtree* st)
{
    pushdown(st);
    //printf("%d %d %d\n", st->l, st->r, st->minv);
    if (st->lchild) {
        output_st(st->lchild);
        output_st(st->rchild);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    root = build(1, n);
    /*printf("---\n");
    output_st(root);
    printf("---\n");
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", dfsorder[i][0], dfsorder[i][1]);
    }*/
    ll wcnt = 0;
    ll ans = -1000000000000000000LL;
    for (ll i = 0; i <= k; i++) {
        //debug("here %lld", i);
        if (i) {
            int node = dfs2node[findmin(root)];
            //debug("here %lld", i);
            //printf("%lld %d\n", i, node);
            int orig = node;
            if (taken[node]) {
                wcnt--;
            } else {
                while (node && !taken[node]) {
                    modify(root, dfsorder[node][0], dfsorder[node][1], -1);
                    /*printf("---\n");
                    output_st(root);
                    printf("---\n");*/
                    taken[node] = true;
                    if (node != orig) wcnt++;
                    node = parent[node];
                }
            }
            modify(root, dfsorder[orig][0], dfsorder[orig][0], -100000000);
        }
        //printf("%lld %lld\n", i, wcnt);
        ll bmin = 1000000000000000000LL;
        bmin = min(bmin, wcnt * (2 * i - (ll)n + wcnt));
        bmin = min(bmin, (n - i) * (i));
        ll val1 = n / 2LL - i;
        if (wcnt <= val1 && val1 <= n - i) {
            bmin = min(bmin, val1 * (2 * i - (ll)n + val1));
        }
        val1 = n / 2LL + 1 - i;
        if (wcnt <= val1 && val1 <= n - i) {
            bmin = min(bmin, val1 * (2 * i - (ll)n + val1));
        }
        ans = max(ans, bmin);
    }
    printf("%lld", ans);
    return 0;
}