#include <bits/stdc++.h>
using namespace std;

int n, x, gas[4];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x), gas[x] ++;
	int mx = gas[1];
	mx = max(mx, gas[2]);
	mx = max(mx, gas[3]);
	printf("%d\n", n - mx);
	return 0;
}