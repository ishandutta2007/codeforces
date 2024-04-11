#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

struct tr{
	bool need;
	int ans44, ans47, ans74, ans77, l, r;
};

int maxv;
char cmd[100];
char s[1000100];
tr rmq[2098100];

inline void push(int v){
	if(!rmq[v].need){
		return;
	}
	swap(rmq[v].ans44, rmq[v].ans77);
	swap(rmq[v].ans47, rmq[v].ans74);
	if(v < maxv){
		rmq[v * 2].need ^= true;
		rmq[v * 2 + 1].need ^= true;
	}
	rmq[v].need = false;
}

inline void calc(int v){
	rmq[v].ans44 = rmq[v * 2].ans44 + rmq[v * 2 + 1].ans44;
	rmq[v].ans47 = max(rmq[v * 2].ans44 + rmq[v * 2 + 1].ans47, max(rmq[v * 2].ans44 + rmq[v * 2 + 1].ans77, rmq[v * 2].ans47 + rmq[v * 2 + 1].ans77));
	rmq[v].ans74 = max(rmq[v * 2].ans77 + rmq[v * 2 + 1].ans44, max(rmq[v * 2].ans77 + rmq[v * 2 + 1].ans74, rmq[v * 2].ans74 + rmq[v * 2 + 1].ans44));
	rmq[v].ans77 = rmq[v * 2].ans77 + rmq[v * 2 + 1].ans77;
}

void update(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].need = true;
		push(v);
		return;
	}
	update(v * 2, l, r);
	update(v * 2 + 1, l, r);
	calc(v);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d %s", &n, &m, s);
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < n; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
		rmq[i + maxv].ans44 = (s[i] == '4');
		rmq[i + maxv].ans77 = (s[i] == '7');
	}
	for(int i = n; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		calc(i);
	}
	for(int i = 0; i < m; i++){
		scanf("%s", cmd);
		if(strcmp(cmd, "count") == 0){
			printf("%d\n", max(max(rmq[1].ans44, rmq[1].ans47), rmq[1].ans77));
			continue;
		}
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		update(1, l, r);
	}
	return 0;
}