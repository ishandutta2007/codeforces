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

const ll inf = (ll)1e14;

struct td{
	ll val;
	int h, sz, l, r;
};

ll sum[100100];
td d[100100];

inline int get_rand(){
	return (rand() << 16) + rand();
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
}

void split(int v, ll val, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[v].val <= val){
		split(d[v].r, val, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, val, l, d[v].l);
		r = v;
	}
	calc(v);
}

int merge(int l, int r){
	if(l == 0){
		return r;
	}
	if(r == 0){
		return l;
	}
	int res;
	if(d[l].h > d[r].h){
		d[l].r = merge(d[l].r, r);
		res = l;
	}
	else{
		d[r].l = merge(l, d[r].l);
		res = r;
	}
	calc(res);
	return res;
}

int main(){
#ifndef HOME
	//freopen("estimate.in", "r", stdin);
	//freopen("estimate.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*printf("%d %I64d\n", 100000, (1LL * 100000 * 100001) / 2);
	for(int i = 0; i < 100000; i++){
		printf("%d ", get_rand());
	}
	printf("\n");
	return 0;*/
	//double start = clock();
	int n;
	ll k;
	scanf("%d %I64d", &n, &k);
	for(int i = 1; i <= n; i++){
		int cur;
		scanf("%d", &cur);
		sum[i] = sum[i - 1] + cur;
	}
	ll ans, l = -inf, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		ll res = 0;
		int cv = 0, sz = 0;
		for(int i = 1; i <= n; i++){
			d[++sz].val = sum[i - 1];
			d[sz].h = get_rand();
			d[sz].sz = 1;
			d[sz].l = d[sz].r = 0;
			int l, r;
			split(cv, sum[i - 1], l, r);
			cv = merge(l, merge(sz, r));
			split(cv, sum[i] - mid, l, r);
			res += d[l].sz;
			cv = merge(l, r);
		}
		if(res >= k){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	printf("%I64d\n", ans);
	//printf("%.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
	return 0;
}