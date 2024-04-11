#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 200010;
const int inf = 0x3f3f3f3f;
struct Edge{
	int u, v, nxt;
}e[maxn];
int c[maxn], head[maxn], e_cnt, val[maxn];
int dfn[maxn], low[maxn], sccno[maxn], scc_cnt, clk, st[maxn], tp;
int flag[maxn];
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
int DFS(int u){
	if(dfn[u]) return dfn[u];
	dfn[u] = low[u] = ++clk;
	st[++tp] = u;
	for(int id = head[u]; id != -1; id = e[id].nxt){
		int v = e[id].v;
		if(!dfn[v])
			low[u] = min(low[u], DFS(v));
		else if(!sccno[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(low[u] >= dfn[u]){
		scc_cnt++;
		val[scc_cnt] = inf;
		int v;
		do{
			v = st[tp--];
			sccno[v] = scc_cnt;
			val[scc_cnt] = min(val[scc_cnt], c[v]);
		}while(u != v);
	}
	return low[u];
}
int main(){
	int n; scanf("%d", &n);
	fill(head + 1, head + 1 + n, -1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++){
		int a; scanf("%d", &a);
		Add(i, a);
	}
	for(int i = 1; i <= n; i++)
		DFS(i);
	for(int i = 0; i < e_cnt; i++){
		if(sccno[e[i].u] == sccno[e[i].v]) continue;
		flag[sccno[e[i].u]] = true;
	}
	long long ans = 0;
	for(int i = 1; i <= scc_cnt; i++)
		if(!flag[i])
			ans += val[i];
	printf("%I64d\n", ans);
	return 0;
}