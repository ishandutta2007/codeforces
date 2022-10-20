#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 300005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, q, stk[MAXN], top;
LL x[MAXN], w[MAXN], ans[MAXN];

inline LL Dist(int i, int j) {
    return (x[j] - x[i]) * (w[i] + w[j]);
}

struct Node {
    int pos;
    LL val;
    Node() {}
    Node(int _pos, LL _val): pos(_pos), val(_val) {}
};
vector<Node> Data[MAXN], Query[MAXN];

struct BIT {
    LL tr[MAXN];
    inline void clean() {
        mset(tr, 0x3f);
    }
    inline void upd(int x, LL v) {
        for (; x <= n; x += (x & (-x))) {
            tr[x] = min(tr[x], v);
        }
    }
    inline LL qry(int x) {
        LL ret = INF;
        for (; x; x -= (x & (-x))) {
            ret = min(ret, tr[x]);
        }
        return ret;
    }
} bit;

void solve() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &x[i], &w[i]);
    }
    stk[top = 0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (top && w[i] < w[stk[top]]) {
            --top;
        }
        if (top) {
            Data[i].push_back(Node(stk[top], Dist(stk[top], i)));
        }
        stk[++top] = i;
    }
    stk[top = 0] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (top && w[i] < w[stk[top]]) {
            --top;
        }
        if (top) {
            Data[stk[top]].push_back(Node(i, Dist(i, stk[top])));
        }
        stk[++top] = i;
    }
    for (int i = 1, l, r; i <= q; ++i) {
        scanf("%d %d", &l, &r);
        Query[r].push_back(Node(l, i));
    }

    bit.clean();
    for (int i = 1; i <= n; ++i) {
        for (auto p : Data[i]) {
            bit.upd(n - p.pos + 1, p.val);
        }
        for (auto p : Query[i]) {
            ans[p.val] = bit.qry(n - p.pos + 1);
        }
    }
    for (int i = 1; i <= q; ++i) {
        printf("%lld\n", ans[i]);
    }
}

int main() {
    solve();
    return 0;
}