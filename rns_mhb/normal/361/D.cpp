#include <bits/stdc++.h>
using namespace std;

#define N 2010
#define inf 2000000001

int n, k, a[N], cal[N], m, num;
long long tt, st, en;

bool test(long long t) {
	if(m <= 1) return true;
	for(int i = 0; i < n; i ++) cal[i] = 1;
	for(int i = 1; i < n; i ++) {
		for(int j = 0; j < i; j ++) {
			int mm = a[j] - a[i];
			if(mm < 0) mm = a[i] - a[j];
			if(1LL * mm <= 1LL * t * (i - j)) if(cal[i] < cal[j] + 1) cal[i] = cal[j] + 1;
		}
		if(cal[i] >= m) return true;
	}

	return false;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	m = n - k;
	st = 0;
	en = inf;
	if(test(st)) {
		puts("0");
		return 0;
	}
	num = 100;
	while(num --) {
		tt = 1LL * (st + en) / 2;
		if (test(tt)) en = tt;
		else st = tt;
	}
	printf("%I64d", en);
}