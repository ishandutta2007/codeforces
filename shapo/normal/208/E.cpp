#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 100500
#define maxl 17

using namespace std;

struct edge{int x, next;};

int pr[maxn][maxl];
int tin[maxn], tout[maxn], lev[maxn];
int beg[maxn];
edge sm[maxn * 2];
int num, n, curt;
vector< int > tree[maxn];
bool used[maxn];
int m;
int ans[maxn];

int add_edge(int x, int y){
	sm[++num].x = y;
	sm[num].next = beg[x];
	beg[x] = num;
	return 0;
}

int compute(){
	for(int i = 1; i < maxl; ++i)
		for(int j = 1; j <= n; ++j)
			pr[j][i] = pr[pr[j][i - 1]][i - 1];
	return 0;
}

int DFS(int x, int lvl){
	++curt;
	used[x] = true;
	lev[x] = lvl;
	tin[x] = curt;
	int i = beg[x];
	tree[lvl].push_back(x);
	while(i){
		if(!used[sm[i].x])DFS(sm[i].x, lvl + 1);
		i = sm[i].next;
	}
	++curt;
	tout[x] = curt;
	return 0;
}


int input_data(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &pr[i][0]);
		if(pr[i][0]){
			add_edge(i, pr[i][0]);
			add_edge(pr[i][0], i);
		}
	}
	return 0;
}

int get_par(int x, int lvl){
	for(int i = 16; i >= 0; --i)
		if(lvl >= (1 << i)){
			lvl -= (1 << i);
			x = pr[x][i];
		}
	return x;
}

int find_ans(int v, int p){
	int par_v = get_par(v, p);
	if(par_v == 0)return 0;
	int fl (lev[par_v]), tiin (tin[par_v]), toout(tout[par_v]);
	int res (0);
	int l = -1, r = tree[fl + p].size();
	while(l < r - 1){
		int m = (l + r) / 2;
		if(toout >= tout[tree[fl + p][m]])
			l = m;
		else
			r = m;
	}
	int ll = l;
	l = -1;
	r = tree[fl + p].size();
	while(l < r - 1){
		int m = (l + r) / 2;
		if(tiin <= tin[tree[fl + p][m]])
			r = m;
		else
			l = m;
	}
	res = ll - r;
	return res;
}

int make_ans(){
	compute();
	for(int i = 1; i <= n; ++i)
		if(pr[i][0] == 0)DFS(i, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		int v, p;
		scanf("%d%d", &v, &p);
		ans[i] = find_ans(v, p);
	   //	if(ans[i])ans[i] -= find_ans(v, p - 1), 0;
	}
	for(int i = 0; i < m; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

int main(){
	input_data();
	make_ans();
	return 0;
}