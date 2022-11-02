#include <bits/stdc++.h>

using namespace std;

#define inf 777777777777LL
#define N 100100

typedef long long LL;

int n, cnt, f[N], vis[N], T;
LL a[N];

int id(LL x) {
	for(int i = 0; i < cnt; i ++) {
		if(a[i] >= x) return i;
	}
}

void init() {
    a[cnt ++] = 3;
    int i = 0, j = 0;
    while(1) {
		++ T;
		int k;
		for(k = i; k <= j; k ++) vis[f[k]] = T;
		for(k = 0; vis[k] == T; k ++);
		f[cnt] = k;
		if((double)a[j] > sqrt(1. * inf) && double(a[i]) > sqrt(sqrt(1.*inf))) {
			a[cnt ++] = inf + 1;
			break;
		}
		LL x = a[i] * a[i] * a[i] * a[i];
		LL y = (a[j] + 1) * (a[j] + 1) - 1;
		a[cnt] = min(x, y);
		if(x == a[cnt]) i ++;
		if(y == a[cnt]) j ++;
		cnt ++;
    }
}

int calc(LL x) {
	for(int i = 0; i < cnt; i ++) {
		if(a[i] >= x) return f[i];
	}
}

int main() {
	init();
	scanf("%d", &n);
	int rt = 0;
	while(n --) {
		LL x;
		scanf("%I64d", &x);
		rt ^= calc(x);
	}
	if(rt) puts("Furlo"); else puts("Rublo");
	return 0;
}