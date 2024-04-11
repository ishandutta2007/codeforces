#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 150100;
vector<int> G[maxn];
int f[maxn];
int Find(int u){ return u == f[u] ? u : f[u] = Find(f[u]); }
void DFS(int u){
	printf("%d ", u);
	for(auto v : G[u]) DFS(v);
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		u = Find(u); v = Find(v);
		G[u].push_back(v);
		f[v] = u;
	}
	DFS(Find(1));
	return 0;
}