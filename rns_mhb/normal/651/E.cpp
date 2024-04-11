#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
void chkmin(int &a, int b) {if (a > b) a = b;}

typedef vector <int> vi;

#define N 1000005

int n, m;
int a[N], b[N], G;
vi v[N], w[N];

int idx(int i, int j) {return m * i + j;}
bool cmp(int x, int y) {return b[x] < b[y];}

int dt[N], d[N], low[N], q[N], qs, cs, c[N], id[N];
bool in[N];

void dfs(int k) {
    dt[k] = low[k] = ++ G;
    in[k] = 1; q[qs ++] = k;
    for (auto x : v[k]) {
        if (!dt[x]) {
			dfs(x);
            chkmin(low[x], low[k]);
        }
        else if (in[x]) chkmin(low[k], dt[x]);
    }
    if (low[k] == dt[k]) {
        cs ++;
        while (q[-- qs] != k) c[q[qs]] = cs, in[q[qs]] = 0;
        c[k] = cs; in[k] = 0;
    }
    return;
}

int func(int k) {
    if (d[k]) return d[k];
    d[k] = 1;
    for (auto x : w[k]) d[k] = max(d[k], func(x) + 1);
    return d[k];
}

int main() {
    scanf("%d %d", &n, &m);
    int up = 0, x, y;
    f0(i, 0, n) f0(j, 0, m) {
        scanf("%d", &x);
        a[up ++] = x;
    }
    f0(i, 0, n) {
        f0(j, 0, m) id[j] = j, b[j] = a[idx(i, j)];
        sort(id, id + m, cmp);
        f0(j, 0, m-1) {
			x = idx(i, id[j]), y = idx(i, id[j+1]);
            v[y].pb(x);
            if (a[x] == a[y]) v[x].pb(y);
        }
    }
    f0(j, 0, m) {
        f0(i, 0, n) id[i] = i, b[i] = a[idx(i, j)];
        sort(id, id + n, cmp);
        f0(i, 0, n-1) {
            x = idx(id[i], j), y = idx(id[i+1], j);
            v[y].pb(x);
            if (a[x] == a[y]) v[x].pb(y);
        }
    }
    f0(i, 0, up) if (!dt[i]) dfs(i);
    f0(i, 0, up) for (auto x : v[i]) if (c[x] != c[i]) w[c[i]].pb(c[x]);
    f1(i, 1, cs) func(i);
    x = 0;
    f0(i, 0, n) {
		f0(j, 0, m) {
			printf("%d ", d[c[x]]);
            x ++;
		}
        puts("");
    }
	return 0;
}