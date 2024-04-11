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

#define INF 1000000000000000000

ll initv[500005];

struct Segtree {
    int l, r;
    Segtree* lchild;
    Segtree* rchild;
    ll minv; int activecnt;
    ll lazy;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->activecnt = r - l + 1;
    st->lazy = INF;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->minv = initv[l];
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        st->minv = min(st->lchild->minv, st->rchild->minv);
    }
    return st;
}

void pushdown(Segtree* st)
{
    if (st->activecnt) {
        st->minv = min(st->minv, st->lazy);
        if (st->lchild) {
            st->lchild->lazy = min(st->lchild->lazy, st->lazy);
            st->rchild->lazy = min(st->rchild->lazy, st->lazy);
        }
        st->lazy = INF;
    }
}

pair<int, ll> findmin(Segtree* st)
{
    pushdown(st);
    if (!st->lchild) {
        return make_pair(st->l, st->minv);
    }
    pushdown(st->lchild);
    pushdown(st->rchild);
    if (st->lchild->minv == st->minv) {
        return findmin(st->lchild);
    } else {
        return findmin(st->rchild);
    }
}

void modify(Segtree* st, int l, int r, ll val)
{
    pushdown(st);
    if (!st->activecnt) return;
    if (r < st->l || st->r < l) return;
    if (l <= st->l && st->r <= r) {
        st->lazy = min(st->lazy, val);
        pushdown(st);
    } else {
        modify(st->lchild, l, r, val);
        modify(st->rchild, l, r, val);
        st->minv = min(st->lchild->minv, st->rchild->minv);
    }
}

void deactivate(Segtree* st, int pos)
{
    pushdown(st);
    if (st->l == st->r) {
        st->minv = INF;
        st->activecnt = 0;
    } else {
        if (pos <= (st->l + st->r) / 2) {
            deactivate(st->lchild, pos);
        } else {
            deactivate(st->rchild, pos);
        }
        st->activecnt = st->lchild->activecnt + st->rchild->activecnt;
        if (st->activecnt) {
            st->minv = min(st->lchild->minv, st->rchild->minv);
        } else {
            st->minv = INF;
        }
    }
}

int n, q;
vector<pair<int, ll> > offers[500005];
ll p[4][500005];
ll finaldist[500005];

struct Segtree2 {
    int l, r;
    Segtree2* lchild;
    Segtree2* rchild;
    ll mina, minb, minpr;
};

Segtree2* build2(int l, int r)
{
    Segtree2* st = new Segtree2;
    st->l = l; st->r = r;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->mina = -p[2][l] + p[3][l-1];
        //printf("!%lld ", st->mina);
        st->minb = INF;
        st->minpr = st->mina + st->minb;
    } else {
        st->lchild = build2(l, (l + r) / 2);
        st->rchild = build2((l + r) / 2 + 1, r);
        st->mina = min(st->lchild->mina, st->rchild->mina);
        st->minb = min(st->lchild->minb, st->rchild->minb);
        st->minpr = min(min(st->lchild->minpr, st->rchild->minpr),
            st->lchild->mina + st->rchild->minb);
    }
    return st;
}

void modifyb(Segtree2* st, int pos, ll val)
{
    /*if (st->l == 1 && st->r == n) {
        printf("modify %d %lld", pos, val);
    }*/
    if (st->l == st->r) {
        st->minb = val;
        st->minpr = st->mina + st->minb;
    } else {
        if (pos <= (st->l + st->r) / 2) {
            modifyb(st->lchild, pos, val);
        } else {
            modifyb(st->rchild, pos, val);
        }
        st->minb = min(st->lchild->minb, st->rchild->minb);
        st->minpr = min(min(st->lchild->minpr, st->rchild->minpr),
            st->lchild->mina + st->rchild->minb);
    }
}

struct QueryRes {
    ll mina, minb, minpr;
};

QueryRes query2(Segtree2* st, int l, int r)
{
    QueryRes qr;
    if (st->r < l || r < st->l) {
        qr.mina = qr.minb = qr.minpr = INF;
        return qr;
    }
    if (l <= st->l && st->r <= r) {
        qr.mina = st->mina;
        qr.minb = st->minb;
        qr.minpr = st->minpr;
        return qr;
    }
    QueryRes left = query2(st->lchild, l, r);
    QueryRes right = query2(st->rchild, l, r);
    qr.mina = min(left.mina, right.mina);
    qr.minb = min(left.minb, right.minb);
    qr.minpr = min(min(left.minpr, right.minpr), left.mina + right.minb);
    return qr;
}

vector<pair<int, ll> > removals[500005];
multiset<ll> endcosts[500005];

int main()
{
    scanf("%d%d", &n, &q);
    for (int lvl = 1; lvl <= 3; lvl++) {
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &(p[lvl][i]));
        }
        for (int i = 1; i <= n; i++) {
            p[lvl][i] += p[lvl][i-1];
        }
    }
    Segtree2* tmp = build2(1, n);
    for (int i = 1; i <= q; i++) {
        int l, r; ll k; scanf("%d%d%lld", &l, &r, &k);
        offers[r].push_back(make_pair(l, k));
        removals[l].push_back(make_pair(r, k));
    }
    for (int i = 1; i <= n; i++) {
        endcosts[i].insert(INF);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < offers[i].size(); j++) {
            pair<int, ll> offer = offers[i][j];
            endcosts[i].insert(offer.second);
        }
        modifyb(tmp, i, *(endcosts[i].begin()));
        initv[i-1] = query2(tmp, i, n).minpr;
        //printf("!%lld %lld %lld %lld", initv[i-1], query2(tmp, 4, n).mina,
        //    query2(tmp, 4, n).minb, query2(tmp, 4, n).minpr);
        for (int j = 0; j < removals[i].size(); j++) {
            pair<int, ll> removal = removals[i][j];
            endcosts[removal.first].erase(endcosts[removal.first].find(removal.second));
            modifyb(tmp, removal.first, *(endcosts[removal.first].begin()));
        }
    }
    initv[n] = INF;
    for (int i = 0; i <= n; i++) {
        //printf("%lld ", initv[i]);
        finaldist[i] = INF;
        //initv[i] = -p[2][i] + p[3][i-1];
    }
    Segtree* root = build(0, n);
    for (int idx = 1; idx <= n + 1; idx++) {
        pair<int, ll> minpair = findmin(root);
        //printf("%d %lld\n", minpair.first, minpair.second);
        int minpos = minpair.first;
        for (int j = 0; j < offers[minpos].size(); j++) {
            pair<int, ll> offer = offers[minpos][j];
            int l = offer.first - 1;
            int r = minpos - 1;
            //printf("! %d %d %lld\n", l, r, minpair.second + offer.second);
            modify(root, l, r, minpair.second + offer.second);
        }
        finaldist[minpos] = min(finaldist[minpos], minpair.second);
        deactivate(root, minpos);
    }
    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, p[2][i-1] - p[1][i] - p[3][n] + finaldist[i-1]);
    }
    printf("%lld", -ans);
    return 0;
}