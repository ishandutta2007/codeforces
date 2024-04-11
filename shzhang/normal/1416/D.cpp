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

struct Tree {
    bool isleaf;
    int val; // deltime if not leaf, node id if leaf
    Tree* left;
    Tree* right;
    Tree* ancestor[20];
    int dfsleft, dfsright;
};

int seq[500005];

struct Segtree {
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
    int maxv; int maxpos;
};


Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->maxv = seq[l]; st->maxpos = l;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        if (st->lchild->maxv > st->rchild->maxv) {
            st->maxv = st->lchild->maxv; st->maxpos = st->lchild->maxpos;
        } else {
            st->maxv = st->rchild->maxv; st->maxpos = st->rchild->maxpos;
        }
    }
    return st;
}

int query_maxv(Segtree* st, int l, int r)
{
    if (l <= st->l && st->r <= r) {
        return st->maxv;
    }
    if (st->r < l || r < st->l) return 0;
    return max(query_maxv(st->lchild, l, r), query_maxv(st->rchild, l, r));
}

void modify(Segtree* st, int idx)
{
    if (st->l == st->r) {
        st->maxv = 0; return;
    }
    if (idx <= (st->l + st->r) / 2) {
        modify(st->lchild, idx);
    } else {
        modify(st->rchild, idx);
    }
    st->maxv = max(st->lchild->maxv, st->rchild->maxv);
}

int n, m, q;

int p[500005]; int invp[500005];
int u[500005], v[500005], deltime[500005];

pair<int, int> qry[500005];


int uf[500005];
Tree* ufnode[500005];
Tree* ufleaf[500005];
int dfsorder[500005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b, int Deltime)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
    Tree* tree = new Tree;
    tree->isleaf = false;
    tree->val = Deltime;
    tree->left = ufnode[a];
    tree->right = ufnode[b];
    ufnode[b] = tree;
}

int dfsnxt = 1;

void dfs(Tree* tree, Tree* prt)
{
    tree->ancestor[0] = prt;
    for (int i = 1; i < 20; i++) {
        tree->ancestor[i] = tree->ancestor[i-1]->ancestor[i-1];
    }
    if (tree->isleaf) {
        dfsorder[tree->val] = dfsnxt++;
        tree->dfsleft = tree->dfsright = dfsnxt - 1;
    } else {
        dfs(tree->left, tree);
        dfs(tree->right, tree);
        tree->dfsleft = tree->left->dfsleft;
        tree->dfsright = tree->right->dfsright;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) {
        ufnode[i] = new Tree;
        ufnode[i]->isleaf = true;
        ufnode[i]->val = i;
        ufnode[i]->left = ufnode[i]->right = NULL;
        ufleaf[i] = ufnode[i];
    }
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 1; i <= n; i++) {
        invp[p[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", u + i, v + i);
        deltime[i] = q + 1;
    }

    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &qry[i].first, &qry[i].second);
    }
    for (int i = 1; i <= q; i++) {
        if (qry[i].first == 2) deltime[qry[i].second] = i;
    }
    vector<pair<int, int> > edges;
    for (int i = 1; i <= m; i++) {
        edges.push_back(make_pair(-deltime[i], i));
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        int edge = edges[i].second;
        un(u[edge], v[edge], -edges[i].first);
    }
    for (int i = 1; i <= n; i++) {
        if (uf[i] == i) dfs(ufnode[i], ufnode[i]);
    }
    for (int i = 1; i <= n; i++) {
        seq[dfsorder[i]] = p[i];
    }
    Segtree* root = build(1, n);
    for (int i = 1; i <= q; i++) {
        if (qry[i].first == 2) continue;
        Tree* curnode = ufleaf[qry[i].second];
        for (int j = 19; j >= 0; j--) {
            if (curnode->ancestor[j]->val > i) {
                curnode = curnode->ancestor[j];
            }
        }
        int qryans = query_maxv(root, curnode->dfsleft, curnode->dfsright);
        printf("%d\n", qryans);
        if (qryans)
            modify(root, dfsorder[invp[qryans]]);
    }
    return 0;
}