#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
#define M 202020
const int mod = 1000000007;

int n;
int Q;
int a[M], b[M];
ll w[M];
vector<int> v[M], to[M];
int dep[M];
int fa[M];
int dt[M], ft[M], tot;

void read(int &x) {
    char c;
    x = 0;
    for (c = getchar(); c > '9' || c < '0'; c = getchar());
    x = c ^ 48;
    for (c = getchar(); c <= '9' && c >= '0'; c = getchar())
        x = x * 10 + (c ^ 48);
}


void read(ll &x) {
    char c;
    x = 0;
    for (c = getchar(); c > '9' || c < '0'; c = getchar());
    x = c ^ 48;
    for (c = getchar(); c <= '9' && c >= '0'; c = getchar())
        x = x * 10 + (c ^ 48);
}

int edge[M];
ll ww[M];

int cnt = 0;
bool isfather(int x, int f) {
    //++cnt;
    return dt[f] <= dt[x] && ft[f] >= ft[x];
}

int root[M];
int q[M], nq;
int find_root(int u) {
    //++cnt;
    if (u == root[u]) return u;
    return root[u] = find_root(root[u]);
}

void solve1() {
    int x, y;
    ll ans;
    read(x);
    read(y);
    read(ans);
    //x = rand() * rand() % n + 1;
    //y = rand() * rand() % n + 1;
    //ans = 1234234895734589ll;
    for (int r = 0; r < 2; r++) {
        while (ans) {
    //        ++cnt;
            x = find_root(x);
            if (isfather(y, x)) break;
            //if (ww[x] == 1) fprintf(stderr, "ERR\n");
            ans /= ww[x];
            x = fa[x];
        }
        swap(x, y);
    }
    char c[20];
    int nc;
    if (!ans) puts("0");
    else {
        nc = 0;
        while (ans) {
            c[nc++] = (ans%10) + '0';
            ans /= 10;
        }
        while(nc) {
            putchar(c[--nc]);
        }
        puts("");
    }
}
void solve2() {
    int p;

    ll c;
    //p = rand() * rand() % (n - 1) + 1;
    read(p);
    read(c);
    //c = 1;
    int x = edge[p];
    if (ww[x] == 1) return;
    ww[x] = c;
    if (c == 1) {
        root[x] = find_root(fa[x]);
    }
}

void solve() {
    int type;
    read(type);
    //type = rand() % 2 + 1;
    if (type == 1) {
        solve1();
    } else {
        solve2();
    }
}

void dfs(int x, int f = 0) {
    dep[x] = dep[f] + 1;
    dt[x] = ++tot;
    for (int y, i = 0; i < v[x].size(); i++) {
        y = to[x][i];
        if (y == f) continue;
        fa[y] = x;
        edge[v[x][i]] = y;
        ww[y] = w[v[x][i]];
        dfs(y, x);
    }
    ft[x] = tot;
}

int main() {
    int siz = 32 << 20;
    char * _ = (char*) malloc(siz) + siz;
    __asm__("movl %0, %%esp\n"::"r"(_));
    //freopen("A4.in", "r", stdin);
    //freopen("AA.out", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &Q);
    for (int i = 1; i < n; i++) {
        read(a[i]);
        read(b[i]);
        read(w[i]);
        //a[i] = i + 1;
        //b[i] = i;
        //b[i] = rand() * rand() % i + 1;
        //w[i] = 1;
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
        to[a[i]].push_back(b[i]);
        to[b[i]].push_back(a[i]);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int x = 2; x <= n; x++) if (ww[x] == 1) root[x] = fa[x];
    while (Q--) solve();
    //fprintf(stderr, "cnt = %d\n", cnt);
    return 0;
    return 0;
    return 0;
}