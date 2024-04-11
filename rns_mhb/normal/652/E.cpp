#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 300005
#define x first
#define y second
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
typedef pair <int, int> pii;
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

vector <int> v[N], av[N];
vector <pii> w;
int T, dt[N], low[N], x[N], y[N], z[N];
int q[N], qs, n, m;
int st, fs, A, B, cs, c[N];
set <pii> St;
bool vis[N];

void dfs(int k, int p = 0) {
	dt[k] = low[k] = ++ T;
	q[qs ++] = k;
    for (auto x : v[k]) {
        if (!dt[x]) {
			dfs(x, k);
            chkmin(low[k], low[x]);
        }
		else if (x != p) chkmin(low[k], dt[x]);
    }
    if (low[k] == dt[k]) {
		cs ++;
        while (q[-- qs] != k) {
			c[q[qs]] = cs;
        }
        c[k] = cs;
        w.pb(pii(p, k));
    }
	return;
}

bool dfs_1(int d, bool ok, int p = 0) {
    ok |= vis[d];
    if (d == B) return ok;
    for (auto x : av[d]) {
        if (x == p) continue;
        bool f = St.count(pii(min(d, x), max(d, x)));
        if (dfs_1(x, f | ok, d)) return 1;
    }
	return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    f1(i, 1, m) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
        v[x[i]].pb(y[i]);
        v[y[i]].pb(x[i]);
    }
    scanf("%d %d", &st, &fs);
    dfs(1);
    for (auto x : w) {
        if (!x.x) continue;
        av[c[x.x]].pb(c[x.y]);
        av[c[x.y]].pb(c[x.x]);
    }
    f1(i, 1, m) {
        if (!z[i]) continue;
        int cx = c[x[i]], cy = c[y[i]];
        if (cx == cy) vis[cx] = 1;
        else St.insert(pii(min(cx, cy), max(cx, cy)));
    }
    A = c[st], B = c[fs];
    if (dfs_1(A, 0)) puts("YES");
    else puts("NO");
	return 0;
}