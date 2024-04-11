#include <cstdio>

using namespace std;

#define ll long long
#define MOD 95542721
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int a[100005];

int n, m;

struct Segtree {
    Segtree* lchild; Segtree* rchild;
    int rotate[48]; int tag;
};

Segtree* rt;

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree; st->tag = 0;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->rotate[0] = a[l];
        for (int i = 1; i < 48; i++) {
            st->rotate[i] = mul(mul(st->rotate[i-1], st->rotate[i-1]), st->rotate[i-1]);
        }
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        for (int i = 0; i < 48; i++) {
            st->rotate[i] = st->lchild->rotate[i] + st->rchild->rotate[i];
            if (st->rotate[i] >= MOD) st->rotate[i] -= MOD;
        }
    }
    return st;
}

void pushdown(Segtree* st)
{
    int newr[48];
    for (int i = 0; i < 48; i++) {
        newr[i] = st->rotate[(i + st->tag) % 48];
    }
    for (int i = 0; i < 48; i++) {
        st->rotate[i] = newr[i];
    }
    if (st->lchild) st->lchild->tag += st->tag;
    if (st->rchild) st->rchild->tag += st->tag;
    st->tag = 0;
}

int query(Segtree* st, int l, int r, int ql, int qr)
{
    if (r < ql || qr < l) return 0;
    if (st->tag) pushdown(st);
    if (ql <= l && r <= qr) return st->rotate[0];
    return (query(st->lchild, l, (l + r) / 2, ql, qr) +
           query(st->rchild, (l + r) / 2 + 1, r, ql, qr)) % MOD;
}

void modify(Segtree* st, int l, int r, int ql, int qr)
{
    if (r < ql || qr < l) {
        pushdown(st); return;
    }
    if (ql <= l && r <= qr) {
        st->tag++; pushdown(st);
    } else {
        pushdown(st);
        modify(st->lchild, l, (l + r) / 2, ql, qr);
        modify(st->rchild, (l + r) / 2 + 1, r, ql, qr);
        for (int i = 0; i < 48; i++) {
            st->rotate[i] = st->lchild->rotate[i] + st->rchild->rotate[i];
            if (st->rotate[i] >= MOD) st->rotate[i] -= MOD;
        }
        pushdown(st);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); a[i] %= MOD;
    }
    rt = build(1, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            printf("%d\n", query(rt, 1, n, l, r));
        } else {
            modify(rt, 1, n, l, r);
        }
    }
    return 0;
}