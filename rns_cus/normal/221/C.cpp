#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N], b[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b + n);
	int dif = 0;
	for (int i = 0; i < n; i ++) if (a[i] !=  b[i]) dif ++;
	if (dif <= 2) puts("YES");
	else puts("NO");
	return 0;
}