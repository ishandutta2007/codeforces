#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 1;

int t, n, m, v, head[N], nxt[N], to[N], eid = 1, d[N];
void addedge(int u, int v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

bool visiting[N];
int dfs(int i){
	if(visiting[i]) return -1;
	if(d[i]) return d[i];
	visiting[i] = true;
	int left = 0, right = 0;
	for(int e = head[i]; e; e = nxt[e]){
		int ret = dfs(to[e]);
		if(ret == -1) return -1;
		if(to[e] < i) left = max(left, ret);
		else right = max(right, ret);
	}
	visiting[i] = false;
	return d[i] = left > right ? left : right + 1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		memset(head + 1, 0, sizeof(int) * n);
		memset(d + 1, 0, sizeof(int) * n);
		memset(visiting + 1, 0, sizeof(bool) * n);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &m);
			while(m--){
				scanf("%d", &v);
				addedge(i, v);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			int ret = dfs(i);
			if(ret == -1){
				ans = -1;
				break;
			}
			ans = max(ans, ret);
		}
		printf("%d\n", ans);
	}
	return 0;
}