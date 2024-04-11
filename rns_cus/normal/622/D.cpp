#include <bits/stdc++.h>
using namespace std;

int n, a[1001001];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i += 2) a[(i+1)/2] = a[n-(i+1)/2+1] = i;
	if (n & 1) a[n/2+1] = n;
	for (int i = 2; i <= n - 1; i += 2) a[n+i/2] = a[n+n-i/2] = i;
	if ((n - 1) & 1) a[n+(n-1)/2+1] = n;
	a[2*n] = n;
	for (int i = 1; i <= 2 * n; i ++) printf("%d ", a[i]);
	puts("");
	return 0;
}