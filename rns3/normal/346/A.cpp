#include <bits/stdc++.h>
using namespace std;

#define N 110

int n, a[N];

int main() {
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	int now = maxx;
	for (int i = 1; i <= n; i ++) {
		now = __gcd(now, a[i]);
	}
	int k = (maxx / now) - n;
	if (k % 2) puts("Alice");
	else puts("Bob");

	return 0;
}