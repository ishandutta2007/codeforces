#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;

int n, head[N], nxt[N << 1], to[N << 1], eid = 1;
void addedge(const int &u, const int &v){
	to[eid] = v;
	nxt[eid] = head[u];
	head[u] = eid++;
}

int maxd, x, res, a, b, c;

int pre[N];
void dfs(int i, int d){
	if(d > maxd){
		maxd = d;
		x = i;
	}
	for(int e = head[i]; e; e = nxt[e]) if(!pre[to[e]]){
		pre[to[e]] = i;
		dfs(to[e], d + 1);
	}
}

int dist[N], q[N], l, r;
void bfs(){
	while(l < r){
		int &i = q[l++];
		if(dist[i] > maxd){
			maxd = dist[i];
			c = i;
		}
		for(int e = head[i]; e; e = nxt[e]) if(!~dist[to[e]]){
			dist[to[e]] = dist[i] + 1;
			q[r++] = to[e];
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; i++){
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	pre[1] = -1;
	dfs(1, 0);
	a = x;
	maxd = 0;
	memset(pre + 1, 0, sizeof(int) * n);
	pre[a] = -1;
	dfs(a, 0);
	b = x;
	res = maxd;
	if(res == n - 1) c = 1 != a && 1 != b ? 1 : (2 != a && 2 != b ? 2 : 3);
	else{
		maxd = 0;
		memset(dist + 1, -1, sizeof(dist));
		for(int i = x; ~i; i = pre[i]){
			dist[i] = 0;
			q[r++] = i;
		}
		bfs();
		res += maxd;
	}
	printf("%d\n%d %d %d", res, a, b, c);
	return 0;	
}