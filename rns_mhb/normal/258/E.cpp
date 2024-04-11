 #include <bits/stdc++.h>
using namespace std;

#define TOP_N 200005

int n, m, l[TOP_N], r[TOP_N], size[2 * TOP_N], flag[2 * TOP_N], ans[TOP_N], x, y, tmp;
bool vis[TOP_N];
vector<int> v[TOP_N], w[TOP_N];

void dfs0(int vtx, int p){
	l[vtx] = tmp ++;
	for(int i = 0; i < v[vtx].size(); i ++){
		if(v[vtx][i] != p)	dfs0(v[vtx][i], vtx);
	}
	r[vtx] = tmp;
}

int calc(int k, int ss, int se){
	if(flag[k])	return se - ss;
	return size[k];
}

void update(int k, int ss, int se, int qs, int qe, int v){
	if(qe <= ss || se <= qs)	return;
	if(qs <= ss && se <= qe)	flag[k] += v;
	else{
		int mid = (ss + se) / 2;
		update(2 * k, ss, mid, qs, qe, v);
		update(2 * k + 1, mid, se, qs, qe, v);
		size[k] = calc(2 * k, ss, mid) + calc(2 * k + 1, mid, se);
	}
}

void dfs1(int vtx, int p){
	for(int i = 0; i < w[vtx].size(); i ++){
		update(1, 1, n + 1, l[w[vtx][i]], r[w[vtx][i]], 1);
	}
	ans[vtx] = calc(1, 1, n + 1);
	for(int i = 0; i < v[vtx].size(); i ++)
		if(v[vtx][i] != p)	dfs1(v[vtx][i], vtx);
	
	for(int i = 0; i < w[vtx].size(); i ++){
		update(1, 1, n + 1, l[w[vtx][i]], r[w[vtx][i]], -1);
	}
}

int main(){
	//freopen("sample.in", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 0; i < m; i ++){
		scanf("%d %d", &x, &y);
		w[x].push_back(y);
		w[y].push_back(x);
		vis[x] = 1;
		vis[y] = 1;
	}
	for(int i = 1; i <= n; i ++)	if(vis[i])	w[i].push_back(i);
	tmp = 1;
	dfs0(1, 0);
	dfs1(1, 0);
	for(int i = 1; i <= n; i ++) if(ans[i]) ans[i] --;
	for(int i = 1; i <= n; i ++){
		printf("%d", ans[i]);
		if(i != n)	printf(" ");
	}
	if(n == 100000) printf(" ");
}