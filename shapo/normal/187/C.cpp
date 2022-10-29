#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 100500
#define maxm 500000

using namespace std;

struct edge{int x, next;};

int n, m, k, num = 0;
int vol[maxn];
edge sm[maxm];
int used[maxn], dist[maxn];
int beg[maxn], mq[maxn];
int par[maxn], v[maxn];
int q, s, t;
int mtrx[2 * maxn][2];
int ibeg, ien;

int init(){
	for(int i = 0; i < maxn; ++i){
		par[i] = i;
		v[i] = 0;
		used[i] = 0;
	}
	return 0;
}

int getroot(const int& x){
	if(par[x] != x)par[x] = getroot(par[x]);
	return par[x];
}

int link(const int& x, const int& y){
	if(v[x] >= v[y])par[y] = x;else par[x] = y;
	if(v[x] == v[y])++v[x];
	return 0;
}

int union_ver(const int& x, const int& y){link(getroot(x), getroot(y));}

int add_edge(const int& x, const int& y, int& num, edge* mass){
	++num;
	mass[num].x = y;
	mass[num].next = beg[x];
	beg[x] = num;
	return 0;
}

int input_data(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i)scanf("%d", &vol[i]);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &mtrx[i][0], &mtrx[i][1]);
		add_edge(mtrx[i][0], mtrx[i][1], num, sm);
		add_edge(mtrx[i][1], mtrx[i][0], num, sm);
	}
	scanf("%d%d", &s, &t);
	++k;
	vol[k] = t;
	return 0;
}

int add_q(const int& x, const int& d, int& num, int* mass){
	++num;
	used[x] = 1;
	mass[num] = x;
	dist[x] = d;
	return 0;
}

int BFS(const int& x, const int &max_deep){
	if(dist[x] < max_deep){
		int i = beg[x];
		while(i != 0){
			if(!used[sm[i].x]){
				union_ver(x, sm[i].x);
				add_q(sm[i].x, dist[x] + 1, ien, mq);
			}
			else{
				if(dist[x] + dist[sm[i].x] + 1 <= max_deep)union_ver(x, sm[i].x);
			}
			i = sm[i].next;
		}
	}
}

bool check(const int& a, const int& b){return(a == s && b == t || a == t && b == s);}

bool ok(const int& len){
	init();
	bool res;
	ibeg = 1;
	ien = 0;
	for(int i = 1; i <= k; ++i)add_q(vol[i], 0, ien, mq);
	while(ibeg <= ien){
		BFS(mq[ibeg], len);
		++ibeg;
	}
	res = (getroot(s) == getroot(t));
	//printf("len = %d, s = %d, t = %d\n", len, getroot(s), getroot(t));
	/*for(int i = 1; i <= n; ++i)
		printf("%d = %d, dist = %d\n", i, getroot(i), dist[i]);*/
	/*if(!res && pt){
		for(int i = 1; i <= m; ++i)
			res = res || check(mtrx[i][0], mtrx[i][1]);
	}*/
	return res;
}

int calc_res(){
	if(!ok(n + 1))q = -1;
	else{
		int il = 0, ir = n + 1;
		while(il < ir - 1){
			int im = (il + ir) / 2;
			if(ok(im))ir = im;else il = im;
		}
		q = ir;
	}
	return 0;
}

int output_data(){
	printf("%d\n", q);
	return 0;
}

int main(){
	//freopen("input.txt", "r", stdin);

	input_data();
	calc_res();
	output_data();

	return 0;
}