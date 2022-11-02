#include<bits/stdc++.h>
using namespace std;

#define N 300030
vector <int> v[N];
int color, col[N], dt[N], dtime;
vector <int> nb[N];
int n, m, x[N], y[N];

void dfs(int x, int pre){
	dt[x] = ++ dtime;
	for(auto y: nb[x]){
		if(y == pre) continue;
		dfs(y, x);
	}
}

void insert(vector <int> &tmp, int val){
	for(auto t : tmp){
		if(t == val) return;
	}
	tmp.push_back(val);
}

map <vector<int>, int> mp;

int main(){
///	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i ++){
		scanf("%d %d", x + i, y + i);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	for(int i = 1; i <= n; i ++){
		v[i].push_back(i);
		sort(v[i].begin(), v[i].end());
	}
	for(int i = 1; i <= n; i ++){
		if(mp[v[i]]){
			col[i] = mp[v[i]];
		}
		else{
			mp[v[i]] = col[i] = ++ color;
		}
	}

	if(color == 1){
		puts("YES");
		for(int i = 1; i <= n; i ++) printf("1 "); puts("");
		return 0;
	}

	for(int i = 1; i <= m; i ++){
		int cx = col[x[i]];
		int cy = col[y[i]];
		if(cx == cy) continue;
		else{
			insert(nb[cx], cy);
			if(nb[cx].size() >= 3){ puts("NO"); return 0; }
			insert(nb[cy], cx);
			if(nb[cy].size() >= 3){ puts("NO"); return 0; }
		}
	}

	int sum = 0, cur = 0;

	for(int i = 1; i <= color; i ++){
		if(nb[i].size() == 1){
			cur = i; break;
		}
	}

	if(cur == 0){ puts("NO"); return 0; }
	dfs(cur, 0);
	puts("YES");
	for(int i = 1; i <= n; i ++){
		printf("%d ", dt[col[i]]);
	}puts("");
}