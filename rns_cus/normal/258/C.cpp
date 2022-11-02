#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define mod 1000000007

int n, a[N], b[N];

void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
void sub(int &x, int y) { x -= y; if(x < 0) x += mod; }

int pp(int x, int y) {
	if(!x) return 0;
	int rt = 1;
	while(y) {
		if(y & 1) rt = 1LL * rt * x % mod;
		x = 1LL * x * x % mod;
		y >>= 1;
	}
	return rt;
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", a + i);
	sort(a, a + n);
	int cur = 0, ans = 0;
	for(int i = 1; i <= a[n - 1]; i ++) {
		int j;
        int m = 0;
		for(j = 1; j * j <= i; j ++) {
			if(i % j == 0) {
				b[m ++] = j;
				if(j != i / j) b[m ++] = i / j;
			}
		}
		sort(b, b + m);
		while(a[cur] < i) cur ++;
		if(cur == 0) {
			add(ans, pp(m, n));
			sub(ans, pp(m - 1, n));
			continue;
		}
		int tp = 1, bf = 0;
        for(int j = 1; j < m; j ++) {
        	int nx = lower_bound(a, a + cur, b[j]) - a;
			tp = 1LL * tp * pp(j, nx - bf) % mod;
			bf = nx;
        }
        int tt = pp(m, n - cur) - pp(m - 1, n - cur);
        if(tt < 0) tt += mod;
        tp = 1LL * tp * tt % mod;
        add(ans, tp);
	}
	printf("%d\n", ans);
	return 0;
}