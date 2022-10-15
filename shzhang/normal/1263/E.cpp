#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long

struct Segtree {
    Segtree* lchild;
    Segtree* rchild;
    int l, r; int tag;
    int minv, maxv;
};

Segtree* st;

Segtree* build(int l, int r)
{
    Segtree* tree = new Segtree;
    tree->l = l;
    tree->r = r;
    tree->tag = 0;
    tree->minv = tree->maxv = 0;
    if (l == r) {
        tree->lchild = tree->rchild = NULL;
    } else {
        tree->lchild = build(l, (l + r) / 2);
        tree->rchild = build((l + r) / 2 + 1, r);
    }
    return tree;
}

void modify(Segtree* tree, int l, int r, int val)
{
    if (tree->tag) {
        tree->minv += tree->tag;
        tree->maxv += tree->tag;
        if (tree->lchild) tree->lchild->tag += tree->tag;
        if (tree->rchild) tree->rchild->tag += tree->tag;
        tree->tag = 0;
    }
    if (tree->r < l || r < tree->l) return;
    if (l <= tree->l && tree->r <= r) {
        tree->minv += val; tree->maxv += val;
        if (tree->lchild) tree->lchild->tag += val;
        if (tree->rchild) tree->rchild->tag += val;
        return;
    }
    modify(tree->lchild, l, r, val);
    modify(tree->rchild, l, r, val);
    tree->minv = min(tree->lchild->minv, tree->rchild->minv);
    tree->maxv = max(tree->lchild->maxv, tree->rchild->maxv);
    //printf("[%d %d] (%d %d): %d %d\n", tree->l, tree->r, l, r, tree->minv, tree->maxv);
}

char cmds[1000005];
int str[1000105];
int cursor = 1;

bool isletter[205];

int total = 0;

int main()
{
    st = build(1, 1000100);
    int n;
    scanf("%d", &n);
    scanf("%s", cmds + 1);
    for (int i = 1; i <= n; i++) {
        if (cmds[i] == 'L') {
            if (cursor > 1) cursor--;
        } else if (cmds[i] == 'R') {
            cursor++;
        } else {
            if (str[cursor] == '(') {
                modify(st, cursor, 1000100, -1); total--;
            } else if (str[cursor] == ')') {
                modify(st, cursor, 1000100, 1); total++;
            }

            if (cmds[i] == '(') {
                modify(st, cursor, 1000100, 1); total++;
            } else if (cmds[i] == ')') {
                modify(st, cursor, 1000100, -1); total--;
            }

            str[cursor] = cmds[i];
        }
        if (st->minv < 0 || total != 0) {
            printf("-1 ");
        } else {
            printf("%d ", st->maxv);
        }
    }
    return 0;
}