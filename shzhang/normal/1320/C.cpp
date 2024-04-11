#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

struct Segtree {
    Segtree* lchild; Segtree* rchild; Segtree* prt;
    int maxv; int tag;
};

Segtree* rt;
Segtree* leaf[1000005];
int initval[1000005];

Segtree* build(int l, int r, Segtree* prt)
{
    Segtree* st = new Segtree; st->prt = prt;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        leaf[l] = st; st->maxv = initval[l];
    } else {
        st->lchild = build(l, (l + r) / 2, st);
        st->rchild = build((l + r) / 2 + 1, r, st);
        st->maxv = max(st->lchild->maxv, st->rchild->maxv);
    }
    st->tag = 0;
    return st;
}

void pushdown(Segtree* st)
{
    st->maxv += st->tag;
    if (st->lchild) st->lchild->tag += st->tag;
    if (st->rchild) st->rchild->tag += st->tag;
    st->tag = 0;
}

void modify(Segtree* st, int l, int r, int ql, int qr, int val)
{
    if (r < ql || qr < l) {
        pushdown(st); return;
    }
    if (ql <= l && r <= qr) {
        st->tag += val; pushdown(st);
    } else {
        pushdown(st);
        modify(st->lchild, l, (l + r) / 2, ql, qr, val);
        modify(st->rchild, (l + r) / 2 + 1, r, ql, qr, val);
        st->maxv = max(st->lchild->maxv, st->rchild->maxv);
        pushdown(st);
    }
}

int n, m, p;
struct Weapon {
    int attack, cost;
};
struct Armor {
    int defense, cost;
};
struct Enemy {
    int defense, attack, value;
};

Weapon weapons[200005];
Armor armors[200005];
Enemy enemies[200005];

bool cmpw(Weapon a, Weapon b)
{
    return a.attack < b.attack;
}

bool cmpa(Armor a, Armor b)
{
    return a.defense < b.defense;
}

bool cmpe(Enemy a, Enemy b)
{
    return a.defense < b.defense;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &(weapons[i].attack), &(weapons[i].cost));
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &(armors[i].defense), &(armors[i].cost));
    }
    for (int i = 1; i <= p; i++) {
        scanf("%d%d%d", &(enemies[i].defense), &(enemies[i].attack), &(enemies[i].value));
    }
    sort(weapons + 1, weapons + n + 1, cmpw);
    sort(armors + 1, armors + m + 1, cmpa);
    sort(enemies + 1, enemies + p + 1, cmpe);
    for (int i = 1; i <= 1000001; i++) initval[i] = -2000000000;
    for (int i = 1; i <= m; i++){
        initval[armors[i].defense] = max(initval[armors[i].defense], -armors[i].cost);
    }
    for (int i = 1000000; i >= 1; i--) {
        initval[i] = max(initval[i], initval[i+1]);
    }
    //for (int i = 1; i <= 30; i++) printf("%d ", initval[i]);
    rt = build(1, 1000000, NULL);
    int ans = -2000000000;
    int nxtenemy = 1;
    for (int i = 1; i <= n; i++) {
        while (nxtenemy <= p && enemies[nxtenemy].defense < weapons[i].attack) {
            modify(rt, 1, 1000000, enemies[nxtenemy].attack + 1, 1000000, enemies[nxtenemy].value);
            nxtenemy++;
        }
        ans = max(ans, rt->maxv - weapons[i].cost);
    }
    printf("%d", ans);
    return 0;
}