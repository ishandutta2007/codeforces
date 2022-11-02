#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using vi = vector <int>;

const int N = 1e5L + 11;

int u[N];

vi e[N];

int sz[N];
int dfn[N], low[N], scc[N];
int cnt = 0, scnt = 0;
stack <int, vi> sta; bool ins[N];
int tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	sta.push(x); ins[x] = 1;
	for(int i : e[x]) low[x] = min(low[x], dfn[i] ? dfn[ins[i] ? i : x] : tarjan(i));
	if(low[x] == dfn[x]) {
		++scnt; int t;
		do {
			t = sta.top(); sta.pop();
			ins[t] = 0; scc[t] = scnt; sz[scnt] ++;
		}while(t != x);
	}
	return low[x];
}

int outdeg[N];

int main() {
	int n, m, h; cin >> n >> m >> h;
	for(int i = 1; i <= n; i ++)
		scanf("%d", u + i);
	for(int i = 1; i <= m; i ++) {
		int a, b; scanf("%d%d", &a, &b);
		if((u[a] + 1) % h == u[b])
			e[a].pb(b);
		if((u[b] + 1) % h == u[a])
			e[b].pb(a);
	}
	
	for(int i = 1; i <= n; i ++)
		if(!dfn[i]) tarjan(i);

	for(int i = 1; i <= n; i ++)
		for(int j : e[i]) if(scc[i] != scc[j])
			outdeg[scc[i]] ++;
	
	int ans = n + 1; int sccid = 0;
	for(int i = 1; i <= scnt; i ++)
		if(!outdeg[i] && sz[i] < ans) {
			sccid = i;
			ans = sz[i];
		}
	cout << ans << '\n';
	for(int i = 1; i <= n; i ++)
		if(scc[i] == sccid)
			printf("%d ", i);
	puts("");
}