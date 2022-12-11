#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, u, r;
ll a[30], b[30], k[30], p[30], newa[30];
ll ans = -1000000000000000000;

void printA() {
	// printf("A:");
	// for (int i = 0; i < n; ++i) printf(" %lld", a[i]);
	// printf("\n");
}

void findAns(int optLeft, bool canxor) {
	// printf("att %d\n", optLeft);
	if (optLeft < 0) return;
	else if (optLeft % 2 == 0) {
		// verify the answer
		ll res = 0;
		for (int i = 0; i < n; ++i) res += (a[i] * k[i]);
		ans = max(ans, res);
	}
	// attept to do an xor maybe?
	if (canxor) {
		// printf("doing xor operation\n");
		for (int i = 0; i < n; ++i) a[i] ^= b[i];
		printA();
		findAns(optLeft - 1, false);
		for (int i = 0; i < n; ++i) a[i] ^= b[i];
	}
	// perform a permute&add
	// printf("doing perm opt\n");
	for (int i = 0; i < n; ++i) newa[i] = a[p[i]] + r;
	swap(a, newa);
	printA();
	findAns(optLeft - 1, true);
	for (int i = 0; i < n; ++i) newa[p[i]] = a[i] - r;
	swap(a, newa);
}


int main() {
	scanf("%d %d %d", &n, &u, &r);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	for (int i = 0; i < n; ++i) scanf("%lld", b + i);
	for (int i = 0; i < n; ++i) scanf("%lld", k + i);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", p + i);
		--p[i];
	}
	findAns(u, true);
	printf("%lld\n", ans);
	return 0;
}