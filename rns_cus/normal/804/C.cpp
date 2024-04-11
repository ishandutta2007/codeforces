#include<bits/stdc++.h>
using namespace std;

#define N 300030

vector <int> v[N];
vector <int> w[N];
int n, m, k, x, y, col[N], ans;
bitset <N> vis;

void DFS(int x, int pre = 0){
	for(int i = 0; i < w[x].size(); i ++){
		if(col[w[x][i]]) vis[col[w[x][i]]] = true;
	}
	int tot = 1;
	for(int i = 0; i < w[x].size(); i ++){
		if(!col[w[x][i]]){
			while(vis[tot]) tot ++;
			col[w[x][i]] = tot ++;
		}
	}
	for(int i = 0; i < w[x].size(); i ++){
		vis[col[w[x][i]]] = false;
	}
	for(int i = 0; i < v[x].size(); i ++) if(v[x][i] != pre) DFS(v[x][i], x);
}

int main(){
	//freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	ans = 1;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &k);
		if(ans < k) ans = k;
		while(k -- ){
			scanf("%d", &x);
			w[i].push_back(x);
		}
	}
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1);
	printf("%d\n", ans);
	for(int i = 1; i <= m; i ++){
		if(col[i]) printf("%d ", col[i]);
		else printf("1 ");
	}
}