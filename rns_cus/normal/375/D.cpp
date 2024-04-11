#include<bits/stdc++.h>
using namespace std;

#define N 200020

int dt[N], ft[N], dtime;
vector <int> v[N];

void dfs(int x, int pre){
	dt[x] = ++ dtime;
	for(auto y : v[x]){
		if(y == pre) continue;
		dfs(y, x);
	}
	ft[x] = dtime;
}

int n, m, c[N], id[N], k[N], st[N], en[N], col[N], x, y, vv[N];

vector <int> seg[N];
bool cmp(int x, int y){
	return en[x] < en[y];
}

int gas[N], ans[N], mp[N];


int tree[100010];
void init(){
	memset(tree, 0, sizeof tree);
	memset(gas, 0, sizeof gas);
}

int main(){
///	freopen("d.in", "r", stdin);

	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", c + i);
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);

	int d = max( (int)sqrt(n / 2), 2) ;

	for(int i = 1; i <= m; i ++){
		scanf("%d %d", vv + i, k + i);
		st[i] = dt[vv[i]];
		en[i] = ft[vv[i]];
		seg[(st[i] + d - 1) / d].push_back(i);
	}

	for(int i = 1; i <= n; i ++) col[dt[i]] = c[i];

	for(int step = 1; step <= n / d + 1; step ++){
		sort(seg[step].begin(), seg[step].end(), cmp);
		init();
		int src = step * d;
		for(auto id : seg[step]){
			for(; src <= en[id]; src ++){
				gas[col[src]] ++;
				tree[gas[col[src]]] ++;
			}
			ans[id] = tree[k[id]];
			for(int dst = min(en[id], step * d - 1); dst >= st[id]; dst --){
				mp[col[dst]] = max(mp[col[dst]], gas[col[dst]]) + 1;
				if(mp[col[dst]] == k[id]) ans[id] ++;
			}
			for(int dst = min(en[id], step * d - 1); dst >= st[id]; dst --){
				mp[col[dst]] = 0;
			}
		}
	}
	for(int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
}