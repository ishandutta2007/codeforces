#include <bits/stdc++.h>
using namespace std;

int n, x, y, one1, one2;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &x, &y);
		if (x) one1 ++;
		if (y) one2 ++;
	}
	printf("%d\n", min(one1, abs(n - one1)) + min(one2, abs(n - one2)));
	return 0;
}