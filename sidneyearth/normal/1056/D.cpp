#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100100;
int c[maxn];
vector<int> G[maxn];
int DFS(int u){
	if(G[u].size() == 0) return c[u] = 1;
	else{
		for(size_t i = 0; i < G[u].size(); i++)
			c[u] += DFS(G[u][i]);
		return c[u];
	}
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int p; scanf("%d", &p);
		G[p].push_back(i);
	}
	DFS(1);
	sort(c + 1, c + 1 + n);
	for(int i = 1; i <= n; i++)
		printf("%d ", c[i]);
	return 0;
}