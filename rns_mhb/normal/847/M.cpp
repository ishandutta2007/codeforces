#include <bits/stdc++.h>
using namespace std;

#define N 10101

int n, a[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	bool flag = 1;
	for (int i = 1; i < n && flag; i ++) if (a[i+1] - a[i] != a[2] - a[1]) flag = 0;
	if (flag) printf("%d\n", a[n] * 2 - a[n-1]);
	else printf("%d\n", a[n]);
	return 0;
}