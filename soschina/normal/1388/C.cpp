#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e5 + 1;

int t, n, m, head[N], nxt[N << 1], to[N << 1], eid;
inline void addedge(int u, int v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

int p[N], h[N], u, v;

int dfs(int i, int fa){
	int pass = 0;
	long long sum = 0;
	for(int e = head[i]; e; e = nxt[e]) if(to[e] != fa){
		int ret = dfs(to[e], i);
		if(ret == -1) return -1;
		pass += ret;
		sum += h[to[e]];
	}
	return h[i] >= sum - p[i] && h[i] <= pass + p[i] && !((long long) abs(sum - p[i] - h[i]) & 1)
	? pass + p[i] : -1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		eid = 1;
		memset(head + 1, 0, sizeof(int) * n);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", p + i);
		for(int i = 1; i <= n; i++) scanf("%d", h + i);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			addedge(u, v), addedge(v, u);
		}
		puts(dfs(1, 0) == m ? "YES" : "NO");
	}
	return 0;
}