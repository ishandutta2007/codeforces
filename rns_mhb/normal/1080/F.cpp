#include <bits/stdc++.h>
using namespace std;
#define N 300100
typedef long long ll;
inline void chkmin(int &x, int y) {
    if (x > y) x = y;
}
const int inf = 1e9 + 7;
struct node {
    int left, right, min_max;
    void init() {
        left = right = 0;
        min_max = inf;
    }
} node[N * 37];

int sz, root[N];

int build(int l, int r) {
    int cur = ++ sz;
    node[cur].init();
    if (l == r) return cur;
    int m = l + r >> 1;
    node[cur].left = build(l, m);
    node[cur].right = build(m + 1, r);
    return cur;
}
int modify(int rt, int l, int r, int k, int d) {
    int cur = ++ sz;
    node[cur] = node[rt];
    if (l == r) {
        chkmin(node[cur].min_max, d);
        return cur;
    }
    int m = l + r >> 1;
    if (k <= m) node[cur].left = modify(node[rt].left, l, m, k, d);
    else node[cur].right = modify(node[rt].right, m + 1, r, k, d);
    node[cur].min_max = max(node[node[cur].left].min_max, node[node[cur].right].min_max);
    return cur;
}
int query(int rt, int L, int R, int l, int r) {
    if (L > r || l > R) return 0;
    if (L <= l && r <= R) return node[rt].min_max;
    int m = l + r >> 1;
    return max(query(node[rt].left, L, R, l, m), query(node[rt].right, L, R, m + 1, r));
}

struct Seg {
    int l, r, id;
    bool operator < (const Seg s) const {
        return l > s.l;
    }
    void in() {
        scanf("%d %d %d", &l, &r, &id);
    }
} s[N];

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i ++) s[i].in();
    sort(s + 1, s + k + 1);
    sz = 0, root[0] = build(1, n);
    for (int i = 1; i <= k; i ++) root[i] = modify(root[i - 1], 1, n, s[i].id, s[i].r);
    while (m --) {
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        x = upper_bound(s + 1, s + k + 1, Seg{x, 0, 0}) - s;
        if (x == 0) puts("no");
        else if (query(root[x - 1], a, b, 1, n) <= y) puts("yes");
        else puts("no");
        fflush(stdout);
    }
}