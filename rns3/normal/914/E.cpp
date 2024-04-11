#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pc putchar
#define gc getchar
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f2(i, a, b) for (int i = a; i > b; i --)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;
const double eps = 1e-7;

#define N 200005

int n;

int tot, nxt[N<<2], head[N], to[N<<2];
ll ans[N];

void add_edge(int x, int y) {
	++ tot;
    to[tot] = y, nxt[tot] = head[x], head[x] = tot;
    return;
}

int a[N];
char s[N];
bool del[N];

int q[N], p[N], qs, son[N];
int bfs(int k) {
	qs = 0;
    q[qs ++] = k; p[k] = 0;
    int l = 0, x, y;
    while (l < qs) {
		x = q[l]; son[x] = 1;
        for (int i = head[x]; i; i = nxt[i]) {
			y = to[i];
            if (del[y] || y == p[x]) continue;
            q[qs ++] = y; p[y] = x;
        }
        l ++;
    }
    int nds = qs;
    while (qs --) {
        x = q[qs];
        if (son[x] * 2 >= nds) return x;
        son[p[x]] += son[x];
    }
}

int h[1<<20], hh[1<<20];

void dfs_1(int k, int p) {
    a[k] = a[p] ^ (1 << s[k] - 'a');
    h[a[k]] ++;
    for (int i = head[k]; i; i = nxt[i]) {
		if (to[i] == p || del[to[i]]) continue;
        dfs_1(to[i], k);
    }
    return;
}

void dfs_2(int k, int p) {
    hh[a[k]] ++;
    for (int i = head[k]; i; i = nxt[i]) {
        if (to[i] == p || del[to[i]]) continue;
        dfs_2(to[i], k);
    }
    return;
}

ll drt;

ll efs(int k, int p, int rt) {
    int v = a[k] ^ a[rt];
    if (__builtin_popcount(a[k]) <= 1) drt ++;
    ll vd = h[v] - hh[v];
    f0(i, 0, 20) vd += h[v^(1<<i)] - hh[v^(1<<i)];
    for (int i = head[k]; i; i = nxt[i]) {
        if (to[i] == p || del[to[i]]) continue;
        vd += efs(to[i], k, rt);
    }
    ans[k] += vd;
    return vd;
}

void dfs_3(int k, int p, bool f) {
    if (f) hh[a[k]] = 0;
    else h[a[k]] = 0;
    for (int i = head[k]; i; i = nxt[i]) {
        if (to[i] == p || del[to[i]]) continue;
        dfs_3(to[i], k, f);
    }
    return;
}

void calc(int rt) {
    a[rt] = 1 << s[rt] - 'a';
    for (int i = head[rt]; i; i = nxt[i]) {
        if (del[to[i]]) continue;
        dfs_1(to[i], rt);
    }
    int g, v; h[a[rt]] ++; ll vd = 0; drt = 0;
    for (int i = head[rt]; i; i = nxt[i]) {
        if (del[to[i]]) continue;
        dfs_2(to[i], rt);
        vd += efs(to[i], rt, rt);
        dfs_3(to[i], rt, 1);
    }
    ans[rt] ++;
    ans[rt] += (vd + drt) / 2;
    dfs_3(rt, 0, 0);
	return;
}

void solve(int k) {
    int rt = bfs(k);
    del[rt] = 1;
    calc(rt);
    for (int i = head[rt]; i; i = nxt[i]) if (!del[to[i]]) solve(to[i]);
    return;
}

int main() {
    scanf("%d", &n);
    int x, y;
    f0(i, 1, n) {
		scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    scanf("%s", s+1);
    solve(1);
	f1(i, 1, n) printf("%I64d ", ans[i]);
	puts("");
	return 0;
}