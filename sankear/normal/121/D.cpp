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
typedef double ld;
typedef complex <double> tc;

const ll inf = (ll)1e18;

struct tp{
	ll l, r;
};

int sz;
ll k, maxd;
tp p[100100];
ll lst[1000000];
ld lf[1000000], rg[1000000];

bool cmp1(const tp &a, const tp &b){
	return a.l > b.l;
}

bool cmp2(const tp &a, const tp &b){
	return a.r < b.r;
}

void gen(int x, ll y, int z){
	if(x > z){
		lst[sz++] = y;
		return;
	}
	gen(x + 1, y * 10 + 4, z);
	gen(x + 1, y * 10 + 7, z);
}

inline bool check(int mid){
	for(int i = 0; i < sz - mid + 1; i++){
		if(lst[i + mid - 1] - lst[i] <= maxd && lf[i] + rg[i + mid - 1] <= k){
			return true;
		}
	}
	return false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %I64d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%I64d %I64d", &p[i].l, &p[i].r);
	}
	maxd = inf;
	for(int i = 0; i < n; i++){
		maxd = min(maxd, p[i].r - p[i].l);
	}
	sz = 0;
	for(int i = 1; i <= 18; i++){
		gen(1, 0, i);
	}
	sort(p, p + n, cmp1);
	int j = 0;
	ld sum = 0;
	for(int i = sz - 1; i >= 0; i--){
		while(j < n && p[j].l > lst[i]){
			sum += p[j].l;
			j++;
		}
		lf[i] = sum - (ld)j * lst[i];
	}
	sort(p, p + n, cmp2);
	j = 0;
	sum = 0;
	for(int i = 0; i < sz; i++){
		while(j < n && p[j].r < lst[i]){
			sum += p[j].r;
			j++;
		}
		rg[i] = (ld)j * lst[i] - sum;
	}
	int ans = 0;
	int l = 1;
	int r = sz;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}