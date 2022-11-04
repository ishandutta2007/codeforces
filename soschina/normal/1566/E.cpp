#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2e5 + 1; 

int t, n, u, v, head[N], nxt[N << 1], to[N << 1], eid = 1;
void addedge(int u, int v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

int cnt, leaves;
bool dfs(int i, int fa){
	if(!nxt[head[i]]) return true;
	int son = 0;
	for(int e = head[i]; e; e = nxt[e]) if(to[e] != fa)
		if(dfs(to[e], i)) son++;
	if(son){
		leaves += son;
		cnt++;
		return false;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		leaves = 0;
		memset(head + 1, 0, sizeof(int) * n);
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		bool flag = true;
		for(int e = head[1]; e; e = nxt[e])
			if(dfs(to[e], 1)) leaves++, flag = false;
		printf("%d\n", leaves - cnt + flag);
	}
	return 0;
}