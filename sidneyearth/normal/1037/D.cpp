#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 200010;
struct Edge{
	int u, v, nxt;
}e[2 * maxn];
int head[maxn], e_cnt, f[maxn], son[maxn], a[maxn];
queue<int> q;
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
void DFS(int u, int fa){
	son[u] = 0; f[u] = fa;
	for(int id = head[u]; id != -1; id = e[id].nxt){
		int v = e[id].v;
		if(v == fa) continue;
		DFS(v, u);
		son[u]++;
	}
}
bool Solve(){
	int p = 1;
	q.push(a[1]);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < son[u]; i++){
//			printf("u:%d a:%d fa:%d\n", u, a[p+1], f[a[p+1]]);
			if(f[a[++p]] != u) return false;
			q.push(a[p]);
		}
	}
	return true;
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		head[i] = -1;
	for(int i = 1; i < n; i++){
		int u, v; 
		scanf("%d%d", &u, &v);
		Add(u, v);
		Add(v, u);
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if(a[1] != 1){
		printf("No\n");
		return 0;
	}
	DFS(a[1], 0);
	printf("%s\n", Solve() ? "Yes" : "No");
	return 0;
}