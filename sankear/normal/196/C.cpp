#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>

using namespace std;

//#define HOME
#define mp make_pair
#define pb push_back

typedef long long ll;

struct point{
	int x, y, num;
};

int cur;
bool used[2000];
int sz[2000], ans[2000];
point p[2000];
vector <int> v[2000], g[2000];

void dfs(int a){
	used[a] = true;
	sz[a] = 1;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i]]){
			g[a].pb(v[a][i]);
			dfs(v[a][i]);
			sz[a] += sz[v[a][i]];
		}
	}
}

bool cmp(const point &a, const point &b){
	return (ll)(a.x - p[cur].x) * (b.y - p[cur].y) - (ll)(b.x - p[cur].x) * (a.y - p[cur].y) > 0;
}

void solve(int l, int r, int v){
	for(int i = l + 1; i <= r; i++){
		if(p[i].y < p[l].y){
			swap(p[i], p[l]);
		}
	}
	ans[p[l].num] = v;
	cur = l;
	sort(p + l + 1, p + r + 1, cmp);
	int pos = l + 1;
	for(int i = 0; i < (int)g[v].size(); i++){
		solve(pos, pos + sz[g[v][i]] - 1, g[v][i]);
		pos += sz[g[v][i]];
	}
}

int main(){
#ifndef HOME
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout); 
#else
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].num = i;
	}
	dfs(0);
	solve(0, n - 1, 0);
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", ans[i] + 1);
	}
	printf("\n");
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}