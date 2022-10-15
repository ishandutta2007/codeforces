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
    int zerocnt;
};

ll psum[200005];

Segtree* build(int l, int r)
{
    Segtree* st = new Segtree;
    st->l = l; st->r = r;
    if (l == r) {
        st->lchild = st->rchild = NULL;
        st->zerocnt = (psum[l] == 0LL ? 1 : 0);
    } else {
        st->lchild = build(l, (l + r) / 2);
        st->rchild = build((l + r) / 2 + 1, r);
        st->zerocnt = st->lchild->zerocnt + st->rchild->zerocnt;
    }
    return st;
}

int n, m;
int l[200005], r[200005];
vector<int> elist[200005];

queue<int> que;

void makezero(Segtree* st, int L, int R)
{
    if (st->r < L || R < st->l) return;
    if (st->zerocnt == st->r - st->l + 1) return;
    if (st->l == st->r) {
        //printf("! %d\n", st->l);
        psum[st->l] = 0;
        for (int idx = 0; idx < elist[st->l].size(); idx++) {
            int intv = elist[st->l][idx];
            if (psum[l[intv]] == 0 && psum[r[intv]] == 0) {
                que.push(intv);
            }
        }
        st->zerocnt = 1;
        return;
    }
    makezero(st->lchild, L, R);
    makezero(st->rchild, L, R);
    st->zerocnt = st->lchild->zerocnt + st->rchild->zerocnt;
}

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", psum + i);
    }
    for (int i = 0; i <= n; i++) elist[i].clear();
    for (int i = 1; i <= n; i++) {
        ll tmp; scanf("%lld", &tmp); psum[i] -= tmp;
    }
    for (int i = 1; i <= n; i++) psum[i] += psum[i-1];
    while (!que.empty()) que.pop();
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", l + i, r + i);
        l[i]--;
        if (psum[l[i]] == 0 && psum[r[i]] == 0) {
            que.push(i);
        }
        elist[l[i]].push_back(i);
        elist[r[i]].push_back(i);
    }
    Segtree* root = build(0, n);
    while (!que.empty()) {
        int intv = que.front();
        que.pop();
        makezero(root, l[intv], r[intv]);
    }
    printf("%s\n", root->zerocnt == n + 1 ? "YES" : "NO");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}