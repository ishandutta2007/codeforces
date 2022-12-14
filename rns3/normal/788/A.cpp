#include <bits/stdc++.h>
using namespace std;

#define N 101010

int a[N], b[N];
long long s[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i ++) b[i] = abs(a[i] - a[i+1]);
	s[0] = 0;
	for (int i = 1; i < n; i ++) {
		if (i & 1) s[i] = s[i-1] + b[i];
		else s[i] = s[i-1] - b[i];
	}
	long long mn = 0, mx = 0;
	for (int i = 1; i < n; i ++) {
		mn = min(mn, s[i]);
		mx = max(mx, s[i]);
	}
	printf("%I64d\n", mx - mn);

	return 0;
}