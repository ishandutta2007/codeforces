#include <bits/stdc++.h>
#define ll long long
#define maxn 2000005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn];
int dfn[maxn], ins[maxn], st[maxn], low[maxn];
int dfcnt, top;
int bel[maxn], col[maxn];
int cnt;
vi th[maxn];
void tarjan(int u) {
	dfn[u]=low[u]=++dfcnt;
	ins[u]=1;
	st[++top]=u;
	for (int i = 0; i < eg[u].size(); i++){
		int v = eg[u][i];
		if (!dfn[v]) 
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (ins[v]) low[u]=min(low[u],low[v]);
	} 
	if (dfn[u]==low[u]) {
		++cnt;
		while (1) {
			bel[st[top]]=cnt;
			th[cnt].pb(st[top]);
			ins[st[top]]=0;
			if (st[top--]==u) break;
		}
	} 
}
int gt(int x, int y) {
	return 2 * (x - 1) + y;
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		int N = n;
		top = 0, dfcnt = 0;
		cnt = 0;
		th[1].clear();
		for (int i = 0; i < N; i++)
			eg[i].clear(), dfn[i] = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			eg[a].pb(b); 
		}
		for (int i = 0; i < N; i++)
			if (!dfn[i]) tarjan(i);
		int fl = 1;
		if (cnt == 1) {
			printf("No\n");
			fl = 0;
		}
		vi r[2];
		if (fl) {
			printf("Yes\n");
			for (int i = 0; i < n; i++)
				col[i] = 1;
			for (int i = 0; i < th[1].size(); i++)
				col[th[1][i]] = 0;
			for (int i = 0; i < n; i++)
				r[col[i]].pb(i + 1);
			printf("%d %d\n", r[0].size(), r[1].size());
			for (int i = 0; i < r[0].size(); i++)
				printf("%d ", r[0][i]);
			printf("\n");
			for (int i = 0; i < r[1].size(); i++)
				printf("%d ", r[1][i]);
			printf("\n");
		}
	}
	return 0;
}