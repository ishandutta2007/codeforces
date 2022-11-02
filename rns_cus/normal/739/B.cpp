#include<bits/stdc++.h>
using namespace std;

#define N 400020

vector <int> v[N], wg[N];

int a[N], p[N], n, w[N];

int tree[N];
int arr[N], ans[N];
long long d[N];

void add(int k, int val){
	for(; k < N; k += k & -k) tree[k] += val;
}

int sum(int k){
	int ret = 0;
	for(; k > 0; k -= k & -k) ret += tree[k];
	return ret;
}

void dfs(int x, int dep){
	ans[x] = -sum(dep - 1);
//	assert(
	for(int i = 0; i < v[x].size(); i ++){
		d[dep + 1] = d[dep] + wg[x][i];
		dfs(v[x][i], dep + 1);
	}
	ans[x] += sum(dep);
	add(dep, -arr[dep]);
	arr[dep] = 0;
	int k = lower_bound(d + 1, d + dep + 1, d[dep] - a[x]) - d;
	if(k < dep){
		arr[k] ++;
		add(k, 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i < n; i ++){
		scanf("%d %d", p + i, w + i);
		v[p[i]].push_back(i + 1);
		wg[p[i]].push_back(w[i]);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i ++) printf("%d ", ans[i]); puts("");
}