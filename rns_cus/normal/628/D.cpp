#include <bits/stdc++.h>
using namespace std;

#define N 2020
#define mod 1000000007

int m, d, a[N], b[N], n, f[N][N], p[N];
char s[N];
void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
void init() {
	f[0][0] = 1;
	p[0] = 1 % m;
	for(int i = 1; i <= n; i ++) p[i] = 10 * p[i-1] % m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < m; j ++) {
			for(int k = 0; k < 10; k ++) if(((n - i) & 1) == (k == d)) {
				add(f[i][(p[i-1] * k + j)% m], f[i - 1][j]);
			}
		}
	}
}

int calc(int *a) {
	int tp = 0, tt = 0, rt = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = a[i] + (i < n); j < 10; j ++) {
			if((i & 1) == (j == d)) continue;
			tt =(tp + j * p[n-i]) % m;
			tt = (m - tt) % m;
			add(rt, f[n-i][tt]);
		}
		if((i & 1) == (a[i] == d)) break;
		tp = (tp + a[i] * p[n-i]) % m;
	}
	return rt;
}

int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d %d\n", &m, &d);
	scanf("%s", s);
	n = strlen(s);
	for(int i = 1; i <= n; i ++) a[i] = s[i-1] - '0';
	scanf("%s", s);
	for(int i = 1; i <= n; i ++) b[i] = s[i-1] - '0';
	init();
	int ans = calc(a);
	int tp = 1;
	for(int i = n; i; i --) {
		int tt = tp + b[i];
		b[i] = tt % 10;
		tp = tt > 9;
	}
	if(!tp) ans -= calc(b);
	if(ans < 0) ans += mod;
	printf("%d\n", ans);
	return 0;
}