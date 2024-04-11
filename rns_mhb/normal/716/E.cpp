#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

const int inf = 0x3f3f3f3f;

#define N 100005
#define M 200005

ll ans;
int head[N], nxt[M], to[M], b[M], del[N];
int n, mod, mx[N], c[N], d[N], tot;
int son[N], nd[N], nds, bpw[N] = {1}, pw[N] = {1};

void add_edge(int x, int y, int z) {
    tot ++;
    nxt[tot] = head[x], to[tot] = y;
    head[x] = tot, b[tot] = z;
    return;
}

void dfs(int k, int p = 0) {
    nd[++ nds] = k; son[k] = 1; mx[k] = 0;
    for (int i = head[k]; i; i = nxt[i]) {
        if (to[i] == p || del[to[i]]) continue;
        dfs(to[i], k);
        son[k] += son[to[i]];
        mx[k] = max(mx[k], son[to[i]]);
    }
    return;
}

map <int, int> mp, rmp;

void dfs_1(int x, int p, int h, int v) {
    c[x] = (c[p] + 1ll * pw[h] * v) % mod;
    mp[c[x]] ++;
    for (int i = head[x]; i; i = nxt[i]) {
        if (del[to[i]] || to[i] == p) continue;
        dfs_1(to[i], x, h + 1, b[i]);
    }
    return;
}

void dfs_2(int x, int p) {
    rmp[c[x]] ++;
    for (int i = head[x]; i; i = nxt[i]) {
        if (del[to[i]] || to[i] == p) continue;
        dfs_2(to[i], x);
    }
    return;
}

void dfs_3(int x, int p, int h, int v) {
    d[x] = (1ll * d[p] * 10 + v) % mod;
    int y = 1ll * (mod - d[x]) * bpw[h] % mod;
    ans += mp[y] - rmp[y];
    for (int i = head[x]; i; i = nxt[i]) if (!del[to[i]] && to[i] != p) dfs_3(to[i], x, h + 1, b[i]);
    return;
}

void calc(int k) {
    mp.clear();
    c[k] = 0; mp[0] ++;
    for (int i = head[k]; i; i = nxt[i]) if (!del[to[i]]) dfs_1(to[i], k, 0, b[i]);
    ans += mp[0] - 1;
    d[k] = 0;
    for (int i = head[k]; i; i = nxt[i]) if (!del[to[i]]) {
        rmp.clear();
        dfs_2(to[i], k);
        dfs_3(to[i], k, 1, b[i]);
    }
}

void solve(int k) {
    nds = 0;
    dfs(k);
    int mn = inf, rt;
    f1(i, 1, nds) {
        mx[nd[i]] = max(mx[nd[i]], nds - son[nd[i]]);
        if (mx[nd[i]] < mn) rt = nd[i], mn = mx[nd[i]];
    }
    del[rt] = 1;
    calc(rt);
    for (int i = head[rt]; i; i = nxt[i]) if (!del[to[i]]) solve(to[i]);
}

void gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    gcd(b, a % b, x, y);
    swap(x, y);
    y -= (a / b) * x;
    return;
}

int main() {
    scanf("%d %d", &n, &mod);
    int ba, x, y, z;
    gcd(10, mod, ba, x);
    ba = (ba + mod) % mod;
    f0(i, 1, N) pw[i] = 1ll * pw[i-1] * 10 % mod;
    f0(i, 1, N) bpw[i] = 1ll * bpw[i-1] * ba % mod;
    f0(i, 1, n) {
        scanf("%d %d %d", &x, &y, &z);
        x ++, y ++;
        add_edge(x, y, z);
        add_edge(y, x, z);
    }
    solve(1);
    printf("%I64d\n", ans);
    return 0;
}