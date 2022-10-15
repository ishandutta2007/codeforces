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
    int ones;
    int tag;
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
};

void pushdown(Segtree* tree)
{
    if (tree->tag == 0) return;
    if (tree->tag == 1) {
        tree->ones = tree->r - tree->l + 1;
    } else if (tree->tag == -1) {
        tree->ones = 0;
    }
    if (tree->lchild) {
        tree->lchild->tag = tree->tag;
        tree->rchild->tag = tree->tag;
    }
    tree->tag = 0;
}

Segtree* build(int l, int r)
{
    Segtree* tree = new Segtree;
    tree->ones = 0; tree->tag = 0;
    tree->l = l; tree->r = r;
    if (l < r) {
        tree->lchild = build(l, (l + r) / 2);
        tree->rchild = build((l + r) / 2 + 1, r);
    } else {
        tree->lchild = tree->rchild = NULL;
    }
    return tree;
}

void cover(Segtree* tree, int l, int r, int val)
{
    pushdown(tree);
    if (tree->r < l || r < tree->l) return;
    if (l <= tree->l && tree->r <= r) {
        tree->tag = (val == 1 ? 1 : -1);
        pushdown(tree);
    } else {
        cover(tree->lchild, l, r, val);
        cover(tree->rchild, l, r, val);
        tree->ones = tree->lchild->ones + tree->rchild->ones;
    }
}

int query(Segtree* tree, int l, int r)
{
    pushdown(tree);
    if (tree->r < l || r < tree->l) return 0;
    if (l <= tree->l && tree->r <= r) {
        return tree->ones;
    }
    return query(tree->lchild, l, r) + query(tree->rchild, l, r);
}

char s[200005];
char f[200005];

void work()
{
    int n, q; scanf("%d%d", &n, &q);
    Segtree* root = build(1, n);
    scanf("%s", s + 1);
    scanf("%s", f + 1);
    for (int i = 1; i <= n; i++) {
        if (f[i] == '1') cover(root, i, i, 1);
    }
    vector<pair<int, int> > ops;
    for (int i = 1; i <= q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        ops.push_back(make_pair(l, r));
    }
    reverse(ops.begin(), ops.end());
    for (int i = 0; i < q; i++) {
        int l = ops[i].first; int r = ops[i].second;
        int ones = query(root, l, r);
        if (ones * 2 < r - l + 1) {
            cover(root, l, r, 0);
        } else if (ones * 2 == r - l + 1) {
            printf("NO\n"); return;
        } else {
            cover(root, l, r, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] - '0' != query(root, i, i)) {
            printf("NO\n"); return;
        }
    }
    printf("YES\n"); return;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}