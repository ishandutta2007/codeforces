#include<bits/stdc++.h>
#define int long long
#define lc ch[x][0]
#define rc ch[x][1]
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 1e5 + 5, S = N * 100;
int n, m, s, t;
int bin[N], top, f[N][51];
int rt, ch[S][2], val[S], sze[S], tot;

int newnode(int v = 0) { ++tot, ch[tot][0] = ch[tot][1] = 0, sze[tot] = 1, val[tot] = v; return tot; }
void pushup(int x) { if(x) sze[x] = sze[lc] + sze[rc] + 1; }
void copy(int x, int y) { ch[x][0] = ch[y][0], ch[x][1] = ch[y][1], val[x] = val[y], sze[x] = sze[y]; }
int rnd() { return rand() * rand(); }

int build(int l, int r) {
    if(l > r) return 0;
    int mid = (l + r) >> 1;
    int u = newnode(bin[mid]);
    if(l == r) return u;
    ch[u][0] = build(l, mid - 1), ch[u][1] = build(mid + 1, r);
    pushup(u);
    return u;
}

int merge(int x, int y) {
    int u = newnode();
    if(!x || !y) { copy(u, x + y); return u; } 
    if(rnd() % (sze[x] + sze[y]) < sze[x]) { copy(u, x), ch[u][1] = merge(ch[x][1], y), pushup(u); return u; }
    else { copy(u, y), ch[u][0] = merge(x, ch[y][0]), pushup(u); return u; }
}

void split(int x, int k, int &u, int &v) {
    if(!x) { u = v = 0; return; }
    if(sze[lc] + 1 <= k) { u = newnode(), copy(u, x), split(rc, k - sze[lc] - 1, ch[u][1], v); }
    else { v = newnode(), copy(v, x), split(lc, k, u, ch[v][0]); }
    pushup(u), pushup(v);
}

void dfs(int x) {
    if(lc) dfs(lc);
    bin[++top] = val[x];
    if(rc) dfs(rc);
}

void Debug(int u) {
    top = 0;
    dfs(u);
    for(int i = 1; i <= top; i++) printf("%d ", bin[i]); printf("\n");
}

int GetRange(int l, int r) {
    while(l <= 0) l += n, r += n;
    while(l > n) l -= n, r -= n;
    if(r > n) return merge(GetRange(l, n), GetRange(1, r - n));
    int a = 0, b = 0, c = 0, d;
    split(rt, r, c, d), split(c, l - 1, a, b);
    // printf("GetRange(%d, %d)\n", l, r);
    // printf("A: "); Debug(a);
    // printf("B: "); Debug(b);
    // printf("C: "); Debug(c);
    // printf("D: "); Debug(d);
    // printf("R: "); Debug(rt);
    return b;
}

void rebuild() {
    top = 0;
    dfs(rt);
    tot = 0, rt = build(1, n);
}

signed main() {
    n = get(), m = get(), s = get(), t = get();
    for(int i = 1; i <= n; i++) bin[i] = i;
    rt = build(1, n);
    // Debug(rt);
    for(int i = 1; i < n; i++) {
        // printf("merge [%d, %d] [%d, %d]\n", 1 + i, m + i, m + 1 - i, n - i);
        rt = merge(GetRange(1 + i, m + i), GetRange(m + 1 - i, n - i));
        if(tot >= S / 2) rebuild();
        // Debug(rt);
    }
    top = 0;
    dfs(rt);
    for(int i = 1; i <= n; i++) f[i][0] = bin[i];
    for(int j = 1; j <= 50; j++)
        for(int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    while(t % n) {
        if(s <= m) s = (s + t % n - 1) % n + 1;
        else s = (s - t % n + n - 1) % n + 1;
        t--;
    }
    t /= n;
    for(int i = 50; i >= 0; i--) 
        if(t >> i & 1) s = f[s][i];
    printf("%d\n", s);
    return 0;
}