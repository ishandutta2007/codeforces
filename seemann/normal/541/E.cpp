#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <complex>

using namespace std;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
	
typedef long long ll;
typedef long double ldb;

const int MAXN = 1010;

int n;

int to[MAXN][MAXN];
int sz[MAXN];

int clr[MAXN];

int maxd[MAXN];
int comp[MAXN];
int csz;

int l[MAXN][MAXN];
int lsz[MAXN];

void dfs(int v, int c) {
	l[csz][lsz[csz]++] = v;
	comp[v] = csz;
	
	clr[v] = c;

	forn(i, sz[v]) {
		int u = to[v][i];
		if (clr[u] == 0) {
			dfs(u, 3 - c);
		} else if (clr[u] == clr[v]) {
			printf("-1\n");
			exit(0);
		}
	}
}

int used[MAXN];
int T;
int d[MAXN];

int q[MAXN];
int b, e;

void bfs(int st) {
	b = e = 0;
	T++;

	used[st] = T;
	d[st] = 0;
	q[e++] = st;

	while (b < e) {
		int v = q[b++];

		forn(i, sz[v]) {
			int u = to[v][i];

			if (used[u] < T) {
				used[u] = T;
				d[u] = d[v] + 1;
				q[e++] = u;
			}
		}
	}

	int c = comp[st];
	forn(i, lsz[c])
		maxd[c] = max(maxd[c], d[l[c][i]]);
}

int main() {
#ifdef LOCAL 
	freopen("input.txt", "r", stdin);
#endif

	int m;
	scanf("%d%d", &n, &m);

	forn(i, n)
		sz[i] = 0;

	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		to[a][sz[a]++] = b;
		to[b][sz[b]++] = a;
	}

	memset(clr, 0, sizeof(clr));
	csz = 0;
	
	forn(i, n)
		if (clr[i] == 0) {
			csz++;
			lsz[csz] = 0;
			dfs(i, 1);
		}

	memset(used, 0, sizeof(used));
	T = 0;

	memset(maxd, 0, sizeof(maxd));

	forn(i, n)
		bfs(i);

	int ans = 0;
	forab(i, 1, csz + 1)
		ans += maxd[i];

	cout << ans << '\n';
	
	return 0;
}