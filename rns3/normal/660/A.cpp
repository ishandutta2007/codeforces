#include <bits/stdc++.h>
using namespace std;
#define M 100100

int n;
int m;
int b[M], a[M];

int main() {
	//freopen("A1.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	b[m = 1] = a[1];
	for (int i = 2; i <= n; i++) {
		int d = __gcd(a[i], a[i-1]);
		if (d > 1) {
			b[++m] = 1;
		}
		b[++m] = a[i];
	}
	printf("%d\n", m-n);
	for (int i = 1; i <= m; i++) {
		printf("%d ", b[i]);
	}
	puts("");
	return 0;
}