#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <map>
#include <set>
#include <cstdio>
#include <utility>
#include <tuple>

using namespace std;

const int MAXK = 524288;
const int MAXQ = 200500;

int n, m, k, q;
vector< pair< int, int > > rooks;
int u[MAXQ], d[MAXQ], l[MAXQ], r[MAXQ];
int curk;
int tree[MAXK * 2];
bool can[MAXQ];

void
init_tree(int n)
{
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    memset(tree, 0, sizeof(tree[0]) * (2 * curk));
}

void
upd_val(int x, int val)
{
    x += curk - 1;
    tree[x] = val;
    while (x != 1) {
        x /= 2;
        tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
    }
}

int
get_min(int l, int r)
{
    int res = MAXK;
    l += curk - 1, r += curk - 1;
    while (l < r) {
        res = min(res, min(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = min(res, tree[l]);
    }
    return res;
}

bool
cmp(int a, int b)
{
    return (r[a] < r[b] || (r[a] == r[b] && l[a] < l[b]));
}

void
check_vars()
{
    // fprintf(stderr, "check_vars\n");
    sort(rooks.begin(), rooks.end());
    vector< int > ids(q);
    for (int i = 0; i < q; ++i) {
        ids[i] = i;
    }
    sort(ids.begin(), ids.end(), cmp);
    int i = 0, j = 0;
    init_tree(m);
    for (int pos = 1; pos <= n; ++pos) {
        // fprintf(stderr, "pos = %d\n", pos);
        while (i < int(rooks.size()) && rooks[i].first <= pos) {
            // fprintf(stderr, "add (%d, %d)\n", rooks[i].first, rooks[i].second);
            upd_val(rooks[i].second, rooks[i].first);
            ++i;
        }
        while (j < int(ids.size()) && r[ids[j]] <= pos) {
            int cur_min = get_min(d[ids[j]], u[ids[j]]);
            if (cur_min >= l[ids[j]]) {
                can[ids[j]] = true;
                // fprintf(stderr, "for id = %d\n", ids[j]);
                // fprintf(stderr, "%d < %d for [%d; %d]\n", cur_min, l[ids[j]], d[ids[j]], u[ids[j]]);
            }
            ++j;
        }
    }
    for (auto &x : rooks) {
        swap(x.first, x.second);
    }
    for (int i = 0; i < q; ++i) {
        swap(l[i], d[i]);
        swap(r[i], u[i]);
    }
    swap(n, m);
}

int
main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    rooks.clear();
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        rooks.push_back({x, y});
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &l[i], &d[i], &r[i], &u[i]);
        can[i] = false;
    }
    check_vars();
    check_vars();
    for (int i = 0; i < q; ++i) {
        if (can[i]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}