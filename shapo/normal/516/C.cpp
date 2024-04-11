#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll INF = 1000000000000000LL;

struct Value
{
    ll max_diff, max_sum, max_all;
    Value(ll md = -INF, ll ms = -INF, ll ma = -INF) : max_diff(md), max_sum(ms), max_all(ma) {}
    Value(const Value &a, const Value &b)
    {
        max_diff = max(a.max_diff, b.max_diff);
        max_sum = max(a.max_sum, b.max_sum);
        max_all = max(a.max_sum + b.max_diff, a.max_diff + b.max_sum);
        max_all = max(max_all, max(a.max_all, b.max_all));
    }
};

vector< Value > tree;
int n, m, curk;
vector< ll > h, d;

ll
get_max_sum(int l, int r)
{
    //fprintf(stdout, "get query (%d, %d)\n", l, r);
    l += curk;
    r += curk;
    Value res;
    while (l < r) {
        if (l % 2 == 1) {
            //printf("merge %d\n", l);
            res = Value(res, tree[l]);
        }
        l = (l + 1) / 2;
        if (r % 2 == 0) {
            //printf("merge %d\n", r);
            res = Value(res, tree[r]);
        }
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = Value(res, tree[l]);
    }
    return res.max_all;
}

int
main()
{
    scanf("%d%d", &n, &m);
    d.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        d[i] = d[i + n] = cur;
    }
    h.resize(2 * n);
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        h[i] = h[i + n] = 2 * cur;
    }
    ll cur_sum = 0ll;
    for (int i = 0; i < 2 * n; ++i) {
        ll tmp = cur_sum;
        cur_sum += d[i];
        d[i] = tmp;
    }
    /*for (int i = 0; i < 2 * n; ++i) {
        printf("%lld ", d[i]);
    } puts("");*/
    curk = 2;
    while (curk < 2 * n) {
        curk *= 2;
    }
    tree.resize(2 * curk);
    for (int i = 0; i < 2 * n; ++i) {
        tree[i + curk] = Value(h[i] - d[i], h[i] + d[i], 0ll);
    }
    for (int i = curk - 1; i >= 1; --i) {
        tree[i] = Value(tree[i * 2], tree[i * 2 + 1]);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        ll res = 0ll;
        if (l <= r) {
            res = get_max_sum(r + 1, l + n - 1);
        } else {
            res = get_max_sum(r + 1, l - 1);
        }
        printf("%lld\n", res);
    }
    return 0;
}