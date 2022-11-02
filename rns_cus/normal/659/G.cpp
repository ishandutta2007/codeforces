#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define N 1001000

int n, h[N], L[N], R[N], M[N];

int sum(int x, int y) {
	return (x + y) % mod;
}

int multi(int x, int y) {
	return (1ll * x * y) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &h[i]), h[i] --;
	if (n == 1) {printf("%d\n", h[1]); return 0;}
	for (int i = 1; i < n; i ++) R[i] = L[i+1] = min(h[i], h[i+1]);
	for (int i = 2; i < n; i ++) M[i] = min(L[i], R[i]);
	int ans = 0;
	for (int i = 1; i <= n; i ++) ans = sum(ans, h[i]);
	int x = 0;
	ans = sum(ans, multi(R[n-1], x =  L[n]));
	for (int i = n - 2; i; i --) {
		x = multi(x, M[i+1]);
		x = sum(x, L[i+1]);
		ans = sum(ans, multi(R[i], x));
	}
	printf("%d\n", ans);
	return 0;
}