#include <bits/stdc++.h>
using namespace std;

#define N 200005

typedef pair<int, int> pii;
int n, m;
pii a[N];

int root;
int son[N][2], val[N], cnt[N], rnd[N], addv[N], addc[N];

void push_down(int x) {
    if (!x) return;
    if (addv[x]) {
        addv[son[x][0]] += addv[x], val[son[x][0]] += addv[x];
        addv[son[x][1]] += addv[x], val[son[x][1]] += addv[x];
        addv[x] = 0;
    }
    if (addc[x]) {
        addc[son[x][0]] += addc[x], cnt[son[x][0]] += addc[x];
        addc[son[x][1]] += addc[x], cnt[son[x][1]] += addc[x];
        addc[x] = 0;
    }
}

void split(int rt, int &x, int &y, int v) {
    if (!rt) { x = y = 0; return; }
    push_down(rt);
    if (val[rt] < v) x = rt, split(son[rt][1], son[x][1], y, v);
    else y = rt, split(son[rt][0], x, son[y][0], v);
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (rnd[x] < rnd[y]) {
        push_down(x);
        son[x][1] = merge(son[x][1], y);
        return x;
    }
    else {
        push_down(y);
        son[y][0] = merge(x, son[y][0]);
        return y;
    }
}

int insert(int x, int y) {
    int r1, r2;
    split(x, r1, r2, val[y]);
    r1 = merge(r1, y);
    x = merge(r1, r2);
    return x;
}

int dfs(int x, int y) {
    if (!x) return y;
    push_down(x);
    y = dfs(son[x][0], y);
    y = dfs(son[x][1], y);
    son[x][0] = son[x][1] = 0;
    return insert(y, x);
}

void down(int x) {
    if (!x) return;
    push_down(x);
    down(son[x][0]);
    down(son[x][1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int c, q;
        scanf("%d %d", &c, &q);
        a[i] = pii(-q, c);
    }
    sort(a, a + n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &val[i]);
        rnd[i] = rand();
        root = insert(root, i);
    }
    for (int i = 0; i < n; i ++) {
        int c = a[i].second;
        int r1, r2, r3, r4;
        split(root, r1, r2, c);
        addv[r2] -= c, val[r2] -= c;
        addc[r2] ++, cnt[r2] ++;
        split(r2, r3, r4, c - 1);
        r1 = dfs(r3, r1);
        root = merge(r1, r4);
    }
    down(root);
    for (int i = 1; i <= m; i ++) printf("%d ", cnt[i]);
    return 0;
}