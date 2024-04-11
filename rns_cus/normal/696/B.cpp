#include<bits/stdc++.h>
using namespace std;

#define N 200010
vector <int> v[N];
int gas[N];
double ans[N];
int n, x;

void dfs(int x){
	for(int i = 0; i < v[x].size(); i ++){
		dfs(v[x][i]);
		gas[x] += gas[v[x][i]] + 1;
	}
}

void DFS(int x){
	double tmp = gas[x];
	for(int i = 0; i < v[x].size(); i ++){
		ans[v[x][i]] = ans[x] + 0.5 * (gas[x] - gas[v[x][i]] + 1);
		DFS(v[x][i]);
	}
}

int main(){
	//freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++){
		scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1);
	ans[1] = 1;
	DFS(1);
	for(int i = 1; i <= n; i ++){
		printf("%lf ", ans[i]);
	}
}