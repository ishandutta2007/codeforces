#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 502;
int n, k;
LL a[N], b[N], A = 0, B = 0;
int f[502][502];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld%lld",&a[i], &b[i]);
		A += a[i], B += b[i];
	}
	if (A/k + B/k == (A+B)/k) return !printf("%lld\n", (A+B)/k);
	LL suml = 0, sumr = 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		LL l = 0, r = 0;
		if (b[i] >= k) {
			l = 0, r = min(a[i], (LL)k);
		} else {
			if (a[i] + b[i] < k) {
				l = 0, r = 0; 
			} else {
				l = k - b[i], r = min((LL)k, a[i]);
			}
		}
		suml += l, sumr += r;
		for (int j = 0; j < k; j ++) {
			if (f[i-1][j]) f[i][j] = 1;
			else {
				for (int x = l; x <= r; x ++) {
					int jj = ((j - x) % k + k) % k;
					if (f[i-1][jj]) f[i][j] = 1;
				}
			}
		}
		//printf("[%lld, %lld]\n", l, r);
	}
	int m1 = A%k, m2 = B%k;
	for (LL x = 0; x < k; x ++) {
		if (f[n][x] == 0) continue;
		LL v1 = ((m1 - x) % k + k) % k; 
		LL v2 = ((m2 - (k-x) % k + k)) % k;
		//printf("%lld %lld %lld %lld %lld\n", m1,m2,x,v1,v2);
		if (v1 + v2 < k) return !printf("%lld\n", (A+B)/k);
	}
	printf("%lld\n", (A+B)/k - 1);
}
/*
4 2
0 

*/