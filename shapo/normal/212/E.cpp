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

#define maxn 5100
#define maxm 15000

using namespace std;

struct edge{int x, next;};

bool can[maxn];
int sm[maxn];
int num;
edge sps[maxm];
int num_e;
int n, beg[maxn];
int col[maxn];
bool used[maxn];
bool res[maxn];

int add_edge(const int &x, const int &y, int &cnum){
	sps[++cnum].x = y;
	sps[cnum].next = beg[x];
	beg[x] = cnum;
	return 0;
}

int input_data(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b, num_e);
		add_edge(b, a, num_e);
	}
	return 0;
}

int DFS(const int &x){
	used[x] = true;
	int i = beg[x];
	while(i){
		if(!used[sps[i].x]){
			DFS(sps[i].x);
			col[x] += col[sps[i].x];
		}
		i = sps[i].next;
	}
	++col[x];
	return 0;
}

int init(){
	memset(used, 0, sizeof(used));
	memset(can, 0, sizeof(can));
	memset(col, 0, sizeof(col));
	num = 0;
	return 0;
}

int count_res(){
	for(int i = 1; i <= n; ++i){
		init();
		DFS(i);
		int cur_go = beg[i];
		//printf("beg[%d] = %d\n", i, beg[i]);
		while(cur_go){
			sm[++num] = col[sps[cur_go].x];
			cur_go = sps[cur_go].next;
		}
		//printf("i = %d, num = %d\n", i, num);
		if(num > 1){
			can[0] = true;
			for(int i = 1; i <= num; ++i)
				for(int ii = n - 1; ii >= sm[i]; --ii)
					can[ii] = can[ii] || can[ii - sm[i]];
			for(int i = 1; i <= n - 2; ++i)res[i] = res[i] || can[i];
		}
	}
	num = 0;
	for(int i = 1; i <= n - 2; ++i)if(res[i])++num;
	printf("%d\n", num);
	for(int i = 1; i <= n - 2; ++i)
		if(res[i])printf("%d %d\n", i, n - 1 - i);
	return 0;
}

int main(){
	input_data();
	count_res();
	return 0;
}