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

static inline pair<int, int> compose(pair<int, int> f1, pair<int, int> f2)
{
    return make_pair(f1.first + max(f2.first - f1.second, 0),
        f2.second + max(f1.second - f2.first, 0));
}

static inline int evaluate(pair<int, int> f, int loc)
{
    if (loc <= f.second) {
        return f.first;
    } else {
        return f.first + loc - f.second;
    }
}

struct Segtree {
    Segtree* lchild;
    Segtree* rchild;
    int l, r;
    pair<int, int> func;
};

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    st->func.first = st->func.second = 0;
    if (l == r) {
        st->lchild = st->rchild = NULL;
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
    }
    return st;
}

void modify(Segtree* st, int pos, pair<int, int> func)
{
    if (st->l == st->r) {
        st->func = func;
        return;
    }
    if (pos <= (st->l + st->r) / 2) {
        modify(st->lchild, pos, func);
    } else {
        modify(st->rchild, pos, func);
    }
    st->func = compose(st->lchild->func, st->rchild->func);
}

pair<int, int> query(Segtree* st, int l, int r)
{
    if (st->r < l || r < st->l) {
        return make_pair(0, 0);
    }
    if (l <= st->l && st->r <= r) {
        return st->func;
    }
    return compose(query(st->lchild, l, r),
        query(st->rchild, l, r));
}

int n;
int a[200005];
int pos[200005];
bool used[200005];

int getdiff(int x, int y, int last)
{
    //printf("! %d %d %d\n", x, y, last);
    // a[x] - a[y] - 1
    if (x > last) return -2;
    if (y > last) return y - x + (1-x%2) - 2;
    return y - (1-y%2) - x + (1-x%2) - 2;
}

void work()
{
    set<int> usedset, usedset_n;
    scanf("%d", &n);
    usedset.insert(n + 1);
    usedset_n.insert(0);
    Segtree* root = build(1, n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[a[i]] = i;
        used[i] = false;
    }
    int last = n;
    int first_used = n + 1;
    int ans = 0;
    for (int iter = 1; iter < n; iter++) {
        int loc = pos[n - iter + 1];
        used[loc] = true;
        while (used[last]) last--;
        first_used = min(first_used, loc);
        int pre = -(*usedset_n.lower_bound(-loc));
        int nxt = *usedset.lower_bound(loc);
        usedset.insert(loc);
        usedset_n.insert(-loc);

        if (pre) {
            modify(root, pre, make_pair(0, getdiff(pre, loc, last)));
        }
        modify(root, loc, make_pair(0, getdiff(loc, nxt, last)));

        if (first_used > last) continue;
        int afirst = n - first_used + 1 - iter + (1-first_used%2);
        pair<int, int> func = query(root, 1, last);
        ans = max(ans, evaluate(func, 0) + afirst);
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}