#include <bits/stdc++.h>
using namespace std;
#define N 200006

vector <int> v[N];
int par[N][20], e[N], f[N], ans[N], a[N], n;
long long d[N][20];

void dfs(int k){
	int i, j;
	long long sum = 0;
	for(i = 1; par[par[k][i - 1]][i - 1]; i++) par[k][i] = par[par[k][i - 1]][i - 1];
	for(i = 1; par[k][i]; i++) d[k][i] = d[par[k][i - 1]][i - 1] + d[k][i - 1];
	i = 19; j = k;
	while(i >= 0){
		if(par[j][i]){
			if(sum + d[j][i] <= a[k]) sum += d[j][i], j = par[j][i];
			else i--;
		}
		else i--;
	}
	f[k] = j;
	if(j != k) e[j]++;
	for(i = 0; i < v[k].size(); i++) dfs(v[k][i]);
}

void dfs_ans(int k){
	int i, j;
	for(i = 0; i < v[k].size(); i++){
		dfs_ans(v[k][i]);
		ans[k] += ans[v[k][i]];
		ans[k] -= e[v[k][i]];
		if(f[v[k][i]] != v[k][i]) ans[k]++;
	}
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", a + i);
	for(i = 2; i <= n; i++){
		scanf("%d %d", &par[i][0], &d[i][0]);
		v[par[i][0]].push_back(i);
	}
	dfs(1);
	dfs_ans(1);
	for(i = 1; i <= n; i++) printf("%d ", ans[i]);
}