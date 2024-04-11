#include<stdio.h>
#include<algorithm>
#include<cstring>
#define int long long

const int N = 5005;
int n, a[N], b[N], cnt[N], ans[N], tot;

int abs(int x) { return x < 0? -x : x; }
int max(int x, int y) { return x > y? x : y; }

void add(int x) {
	if(b[x] == 0) return;
	if(cnt[x] == 0) tot++;
	cnt[x]++;
} 

signed main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) {
		int tmp = abs(a[i]);
		for(int j = 2; j * j <= tmp; j++)
			while(!(a[i] % (j * j))) a[i] /= j * j;
		b[i] = a[i];
	}
	std::sort(b + 1, b + 1 + n);
	int len = std::unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++) a[i] = std::lower_bound(b + 1, b + 1 + len, a[i]) - b;
	for(int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt)), tot = 0;
		for(int j = i; j <= n; j++) 
			add(a[j]), ans[max(tot, 1ll)]++;
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}