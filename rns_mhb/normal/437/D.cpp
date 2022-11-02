#include <bits/stdc++.h>
using namespace std;
#define N 100005

vector <int> v[N];
int a[N], id[N], sz[N], rt[N];
long long ans;
bool vis[N];
double rlt;

bool cmp(int x, int y){
	return a[x] > a[y];
}

int find_rt(int x){
	if(rt[x] == x) return x;
	rt[x] = find_rt(rt[x]);
	return rt[x];
}

int main(){
	int m, n, i, j, x, y, k;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++){
		scanf("%d", a + i);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	while(m--){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i = 1; i <= n; i++){
		rt[id[i]] = id[i];
		vis[id[i]] = 1;
		sz[id[i]] = 1;
		for(j = 0; j < v[id[i]].size(); j++){
			x = v[id[i]][j];
			if(!vis[x]) continue;
			y = find_rt(x);
			if(y == id[i]) continue;
			ans += 1ll * sz[id[i]] * a[id[i]] * sz[y];
			sz[id[i]] += sz[y];
			rt[y] = id[i];
		}
	}
	rlt = 2.0 * ans / (1ll * n * (n - 1));
	printf("%lf", rlt);
}