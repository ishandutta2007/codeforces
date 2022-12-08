#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 3e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n, q, x[N], w[N], ans[N];
int st[N], top;
struct Node { int l, r, w; Node(int a = 0, int b = 0, int c = 0) { l = a, r = b, w = c; } };
vector<Node> bin[N], ask[N];

namespace BIT {
    int mn[N];
    void init() { memset(mn, 0x3f, sizeof(mn)); }
    int lowbit(int x) { return x & -x; }
    void add(int x, int v) { while(x) mn[x] = min(mn[x], v), x -= lowbit(x); }
    int ask(int x) { int r = inf; while(x <= n) r = min(r, mn[x]), x += lowbit(x); return r; }
}

main() {
    n = get(), q = get();
    for(int i = 1; i <= n; i++) x[i] = get(), w[i] = get();
    for(int i = 1, l, r; i <= q; i++) l = get(), r = get(), ask[r].emplace_back(l, r, i);

    top = 0;
    for(int i = 1; i <= n; i++) {
        while(top && w[st[top]] > w[i]) --top;
        if(top) bin[i].emplace_back(st[top], i, (x[i] - x[st[top]]) * (w[i] + w[st[top]]));
        st[++top] = i;
    }
    top = 0;
    for(int i = n; i >= 1; i--) {
        while(top && w[st[top]] > w[i]) --top;
        if(top) bin[st[top]].emplace_back(i, st[top], (x[st[top]] - x[i]) * (w[i] + w[st[top]]));
        st[++top] = i;
    }

    BIT::init();
    for(int i = 1; i <= n; i++) {
        for(auto v : bin[i]) BIT::add(v.l, v.w);
        for(auto v : ask[i]) ans[v.w] = BIT::ask(v.l);
    }
    for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}