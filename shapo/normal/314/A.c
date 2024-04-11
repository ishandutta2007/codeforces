#include <stdio.h>

#define maxn 200500

typedef long long ll;

int a[maxn];
int up, n, k, cnt;
ll cursum, diff;

int main() {
	int i;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	cursum = 0LL;
	up = 0;
	cnt = 0;
	for (i = 1; i <= n; ++i) {
		diff = (ll)(-a[i]) * (n - i) * cnt;
		diff += cursum;
		if (diff < (ll)k) {
			printf("%d\n", i);
		} else {
			cursum += (ll)(a[i]) * cnt;
			++cnt;
		}
	}
	return 0;
}