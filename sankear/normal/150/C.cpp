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

struct tr{
	double sum, ans, pref, suff;
	int l, r;
};

int maxv, sz;
double p[600600], a[600600], x[600600];
int lst[600600];
tr rmq[600600];

void dfs(int v, int l, int r){
	if(rmq[v].l > r || rmq[v].r < l){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		lst[sz++] = v;
		return;
	}
	dfs(v * 2, l, r);
	dfs(v * 2 + 1, l, r);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	double c;
	scanf("%d %d %lf", &n, &m, &c);
	for(int i = 0; i < n; i++){
		scanf("%lf", &x[i]);
	}
	for(int i = 0; i < n - 1; i++){
		scanf("%lf", &p[i]);
		p[i] /= 100;
	}
	for(int i = 0; i < n - 1; i++){
		a[i] = (x[i + 1] - x[i]) / 2 - p[i] * c;
	}
	maxv = 1;
	while(maxv < n - 1){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
		rmq[i + maxv].sum = a[i];
		rmq[i + maxv].ans = rmq[i + maxv].pref = rmq[i + maxv].suff = max(a[i], (double)0);
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		rmq[i].sum = rmq[i * 2].sum + rmq[i * 2 + 1].sum;
		rmq[i].ans = max(rmq[i * 2].suff + rmq[i * 2 + 1].pref, max(rmq[i * 2].ans, rmq[i * 2 + 1].ans));
		rmq[i].pref = max(rmq[i * 2].pref, rmq[i * 2].sum + rmq[i * 2 + 1].pref);
		rmq[i].suff = max(rmq[i * 2 + 1].suff, rmq[i * 2 + 1].sum + rmq[i * 2].suff);
	}
	double ans = 0;
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		sz = 0;
		dfs(1, a - 1, b - 2);
		double res = 0, suff = 0;
		for(int j = 0; j < sz; j++){
			res = max(res, max(rmq[lst[j]].ans, suff + rmq[lst[j]].pref));
			suff = max(rmq[lst[j]].suff, rmq[lst[j]].sum + suff);
		}
		ans += res;
	}
	printf("%.18lf\n", ans);
	return 0;
}