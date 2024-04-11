#include <cstdio>

#define N 400200

int n, a[N], p[N], m, fl[N];
long long ans;

int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }

int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", a + i);
	for(int i = 1; i * i <= n; i ++) {
		if(n % i == 0) {
			p[m ++] = i; if(i * i != n && i != 1) p[m ++] = n / i;
		}
	}
	for(int i = 0; i < m; i ++) {
		int d = p[i], r = n / p[i];
		for(int j = 0; j < n; j ++) fl[j] = 0;
		for(int j = 0; j < d; j ++) {
			int mx = 0;
			for(int k = 0; k < r; k ++) {
				int tp = k * d + j;
				if(mx < a[tp]) mx = a[tp];
			}
			for(int k = 0; k < r; k ++) {
				int tp = k * d + j;
				if(mx == a[tp]) fl[tp] = 1;
			}
		}
		int cnt = 0, tt;
		for(int j = 0; j < n; j ++) {
			if(!fl[j]) {
				if(cnt >= d) {
					tt = cnt / d;
					for(int k = 1; k <= tt; k ++) if(gcd(k, r) == 1) ans += cnt - d * k + 1;
				}
				cnt = 0;
			} else cnt ++;
		}
		if(cnt) {
			int j;
			for(j = 0; j < n; j ++) if(!fl[j]) break;
			tt = (cnt + j) / d;
			for(int k = 1; k <= tt && k < r; k ++) if(gcd(k, r) == 1) {
				int tp = d * k;
				if(j + 1>= tp) ans+=cnt;
				else {
					ans += cnt + j - tp + 1;
				}
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}