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

#define maxn 300000

using namespace std;

struct edge{int x, next;};

int n, m, num = 0, num_r = 0;
int beg[maxn], en[maxn];
int beg_r[maxn], en_r[maxn];
edge sm[maxn], sm_r[maxn];
int val[maxn];
bool find1[maxn], find2[maxn];
int used[maxn], used_r[maxn];

int add(const int &x, const int &y, int &num, int *bg, int *enn, edge *cur_m){
	++num;
	cur_m[num].x = y;
	cur_m[num].next = 0;
	if(bg[x] == 0)bg[x] = num;
	if(enn[x] != 0)cur_m[enn[x]].next = num;
	enn[x] = num;
	return 0;
}

int DFS1(const int &x){
	used[x] = true;
	find1[x] = true;
	int i = beg[x];
	while(i != 0){
		if(val[sm[i].x] != 1 && !used[sm[i].x])DFS1(sm[i].x);
		i = sm[i].next;
	}
	return 0;
}

int DFS2(const int &x){
	used_r[x] = true;
	find2[x] = true;
	if(val[x] != 1){
		int i = beg_r[x];
		while(i != 0){
			if(!used_r[sm_r[i].x])DFS2(sm_r[i].x);
			i = sm_r[i].next;
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)scanf("%d", &val[i]);
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b, num, beg, en, sm);
		add(b, a, num_r, beg_r, en_r, sm_r);
	}
	for(int i = 1; i <= n; ++i){
		if(!used[i] && val[i] == 1)DFS1(i);
		if(!used_r[i] && val[i] == 2)DFS2(i);
	}
	
	for(int i = 1; i <= n; ++i)
		if(find1[i] && find2[i])printf("1\n");else printf("0\n");
	
	return 0;
}