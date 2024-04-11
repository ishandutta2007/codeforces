#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;

const int maxn = 100100;
const int steps = 16;

int cur;
bool used[maxn], use[maxn];
int tin[maxn], col[maxn], a[maxn], b[maxn], h[maxn], lst[maxn];
int p[steps + 1][maxn];
vector <int> g[maxn], rg[maxn], go[maxn];
vector <pii> v[maxn];

void dfs1(int a){
	used[a] = true;
	tin[a] = cur++;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i].first]){
			use[v[a][i].second] = true;
			dfs1(v[a][i].first);
		}
	}
}

void dfs2(int a){
	used[a] = true;
	for(int i = 0; i < (int)g[a].size(); i++){
		if(!used[g[a][i]]){
			dfs2(g[a][i]);
		}
	}
	lst[cur++] = a;
}

void dfs3(int a){
	col[a] = cur;
	for(int i = 0; i < (int)rg[a].size(); i++){
		if(col[rg[a][i]] == 0){
			dfs3(rg[a][i]);
		}
	}
}

void dfs4(int a, int b){
	used[a] = true;
	h[a] = b;
	for(int i = 0; i < (int)go[a].size(); i++){
		if(!used[go[a][i]]){
			p[0][go[a][i]] = a;
			dfs4(go[a][i], b + 1);
		}
	}
}

inline int getlca(int a, int b){
	if(h[a] < h[b]){
		swap(a, b);
	}
	for(int i = steps; i >= 0; i--){
		if(p[i][a] != -1 && h[p[i][a]] >= h[b]){
			a = p[i][a];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = steps; i >= 0; i--){
		if(p[i][a] != p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}

int main(){
	//freopen("hexagram.in", "r", stdin);
	//freopen("hexagram.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		v[a[i]].pb(mp(b[i], i));
		v[b[i]].pb(mp(a[i], i));
	}
	cur = 0;
	dfs1(0);
	for(int i = 0; i < m; i++){
		if(use[i]){
			if(tin[a[i]] < tin[b[i]]){
				g[a[i]].pb(b[i]);
				rg[b[i]].pb(a[i]);
			}
			else{
				g[b[i]].pb(a[i]);
				rg[a[i]].pb(b[i]);
			}
		}
		else{
			if(tin[a[i]] > tin[b[i]]){
				g[a[i]].pb(b[i]);
				rg[b[i]].pb(a[i]);
			}
			else{
				g[b[i]].pb(a[i]);
				rg[a[i]].pb(b[i]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		used[i] = false;
	}
	cur = 0;
	dfs2(0);
	cur = 0;
	for(int i = n - 1; i >= 0; i--){
		if(col[lst[i]] == 0){
			cur++;
			dfs3(lst[i]);
		}
	}
	for(int i = 0; i < m; i++){
		go[col[a[i]]].pb(col[b[i]]);
		go[col[b[i]]].pb(col[a[i]]);
	}
	for(int i = 1; i <= cur; i++){
		used[i] = false;
	}
	for(int i = 0; i <= steps; i++){
		for(int j = 1; j <= cur; j++){
			p[i][j] = -1;
		}
	}
	dfs4(1, 0);
	for(int i = 1; i <= steps; i++){
		for(int j = 1; j <= cur; j++){
			if(p[i - 1][j] == -1){
				continue;
			}
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int f, t;
		scanf("%d %d", &f, &t);
		f--;
		t--;
		int lca = getlca(col[f], col[t]);
		printf("%d\n", h[col[f]] + h[col[t]] - 2 * h[lca]);
	}
	return 0;
}