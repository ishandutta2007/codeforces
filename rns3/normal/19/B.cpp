#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 2020

int n, m, t, c;

long long d[N], e;

int main() {
	e = 10000000000000000ll;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) d[i] = e;
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &t, &c);
		for (int j = n; j >= 0; j --) {
			m = min(n, j + 1 + t);
			d[m] = min(d[m], d[j] + c);
		}
	}
	printf("%I64d\n", d[n]);
	return 0;
}