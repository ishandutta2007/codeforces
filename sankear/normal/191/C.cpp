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
#define prev _prev

typedef long long ll;

const int steps = 16;
const int maxn = 100100;

struct tr{
	ll sum, add;
	int l, r;
};

int maxv, cnt;
bool used[maxn];
int h[maxn], prev[maxn], sz[maxn], lst[maxn], pr[maxn], pos[maxn], look[maxn];
vector <int> v[maxn], num[maxn];
int p[steps + 1][maxn];
tr rmq[4 * maxn];

void dfs1(int a, int b){
	used[a] = true;
	h[a] = b;
	sz[a] = 1;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(!used[v[a][i]]){
			p[0][v[a][i]] = a;
			pr[v[a][i]] = num[a][i];
			dfs1(v[a][i], b + 1);
			sz[a] += sz[v[a][i]];
		}
	}
}

void dfs2(int a, int b){
	prev[a] = b;
	pos[a] = cnt;
	lst[cnt++] = (p[0][a] != -1 ? pr[a] : -1);
	int best = -1;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(p[0][v[a][i]] == a && (best == -1 || sz[v[a][i]] > sz[best])){
			best = v[a][i];
		}
	}
	if(best != -1){
		dfs2(best, b);
	}
	for(int i = 0; i < (int)v[a].size(); i++){
		if(p[0][v[a][i]] == a && v[a][i] != best){
			dfs2(v[a][i], v[a][i]);
		}
	}
}

inline int lca(int a, int b){
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

inline void push(int v){
	rmq[v].sum += rmq[v].add * (rmq[v].r - rmq[v].l + 1);
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

inline void calc(int v){
	rmq[v].sum = rmq[v * 2].sum + rmq[v * 2 + 1].sum;
}

void update(int v, int l, int r, int val){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add = val;
		push(v);
		return;
	}
	update(v * 2, l, r, val);
	update(v * 2 + 1, l, r, val);
	calc(v);
}

inline ll get(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return 0;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		return rmq[v].sum;
	}
	ll res = get(v * 2, l, r) + get(v * 2 + 1, l, r);
	calc(v);
	return res;
}

inline void go(int a, int b){
	while(prev[a] != prev[b]){
		update(1, pos[prev[a]], pos[a], 1);
		a = p[0][prev[a]];
	}
	update(1, pos[b] + 1, pos[a], 1);
}

int main(){
#ifndef HOME
	//freopen("doubledealing.in", "r", stdin);
	//freopen("doubledealing.out", "w", stdout);
#else
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
		num[a].pb(i);
		v[b].pb(a);
		num[b].pb(i);
	}
	for(int i = 0; i <= steps; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	dfs1(0, 0);
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < n; j++){
			if(p[i - 1][j] == -1){
				continue;
			}
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}
	cnt = 0;
	dfs2(0, 0);
	for(int i = 0; i < cnt; i++){
		look[lst[i]] = i;
	}
	maxv = 1;
	while(maxv < cnt){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d %d", &v, &u);
		v--;
		u--;
		int vu = lca(v, u);
		go(v, vu);
		go(u, vu);
	}
	for(int i = 0; i < n - 1; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%I64d", get(1, look[i], look[i]));
	}
	printf("\n");
	return 0;
}