#include <cstdio>
#include <algorithm>
#include <cstdint>

using namespace std;

struct Action {
    bool is_add; int queryid;
};

struct Segtree {
    Segtree* parent; Segtree* lchild; Segtree* rchild;
    uint8_t f[105];
};

int orig[200005];
Action actions[400005];
Segtree* leaf[200005];
int l[200005], r[200005], x[200005], y[200005];

static inline int action_time(Action a)
{
    return a.is_add ? l[a.queryid] : r[a.queryid] + 1;
}

Segtree* build(int L, int R, Segtree* prt)
{
    Segtree* st = new Segtree; st->parent = prt;
    if (L == R) {
        st->lchild = st->rchild = NULL;
        leaf[L] = st; //fprintf(stderr, "set leaf %d\n", L);
    } else {
        st->lchild = build(L, (L + R) / 2, st);
        st->rchild = build((L + R) / 2 + 1, R, st);
    }
    for (uint8_t i = 1; i <= 100; i++) st->f[i] = i;
    return st;
}

int n, q;

void recalc(Segtree* st)
{
    uint8_t* funca = st->lchild->f;
    uint8_t* funcb = st->rchild->f;
    uint8_t* funcc = st->f;
    for (uint8_t i = 1; i <= 100; i++) funcc[i] = funcb[funca[i]];
}

bool cmp(Action a, Action b)
{
    return action_time(a) < action_time(b);
}

Segtree* rt;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", orig + i);
    scanf("%d", &q);
    int nxt = 1;
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d%d", l + i, r + i, x + i, y + i);
        actions[nxt].is_add = true;
        actions[nxt].queryid = actions[nxt+1].queryid = i;
        nxt += 2;
    }
    sort(actions + 1, actions + nxt, cmp);
    rt = build(1, q, NULL);
    int nextact = 1;
    for (int i = 1; i <= n; i++) {
        while (nextact < nxt && action_time(actions[nextact]) <= i) {
            int qryid = actions[nextact].queryid;
            //fprintf(stderr, "leaf %d\n", qryid);
            Segtree* changed = leaf[qryid];
            if (actions[nextact].is_add) {
                changed->f[x[qryid]] = y[qryid];
            } else {
                changed->f[x[qryid]] = x[qryid];
            }
            changed = changed->parent;
            while (changed) {
                recalc(changed); changed = changed->parent;
            }
            nextact++;
        }
        printf("%d ", rt->f[orig[i]]);
    }
    return 0;
}