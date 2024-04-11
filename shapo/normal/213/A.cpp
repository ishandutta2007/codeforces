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

#define maxn 250

using namespace std;

struct home{int q[maxn], beg, en;};
struct edge{int x, next;};

int n;
int st[maxn];
home mass[3];
int num[maxn];
int ne;
edge sm[maxn * maxn];
int beg[maxn];
int res = 100500;
int tmp[maxn];

int add_edge(int x, int y){
	sm[++ne].x = x;
	sm[ne].next = beg[y];
	beg[y] = ne;
	++st[x];
	return 0;
}

int input_data(){
	scanf("%d", &n);
	ne = 0;
	for(int i = 1; i <= n; ++i)
		scanf("%d", &num[i]);
	for(int i = 1; i <= n; ++i){
		--num[i];
		int k (0);
		scanf("%d", &k);
		for(int ii = 0; ii < k; ++ii){
			int dest (0);
			scanf("%d", &dest);
			add_edge(i, dest);
		}
	}
	return 0;
}

int add_q(int x, home& cp){
	cp.q[++cp.en] = x;
	return 0;
}

int gogo(int x){
	int i = beg[x];
	while(i){
		--tmp[sm[i].x];
		if(!tmp[sm[i].x])add_q(sm[i].x, mass[num[sm[i].x]]);
		i = sm[i].next;
	}
	return 0;
}

int try_home(int nh){
	int ct (0), obr (0);
	for(int i = 0; i < 3; ++i){
		mass[i].beg = 1;
		mass[i].en = 0;
	}
	for(int i = 1; i <= n; ++i)tmp[i] = st[i];
	for(int i = 1; i <= n; ++i)
		if(!tmp[i])add_q(i, mass[num[i]]);
	while(obr < n){
		while(mass[nh].beg <= mass[nh].en){
			++obr;
			++ct;
			if(obr > n)return 0;
			gogo(mass[nh].q[mass[nh].beg]);
			++mass[nh].beg;
		}
		++ct;
		nh = (nh + 1) % 3;
	}
	res = min(res, ct - 1);
	return 0;
}

int main(){
	input_data();
	for(int i = 0; i < 3; ++i)try_home(i);
	printf("%d\n", res);
	return 0;
}