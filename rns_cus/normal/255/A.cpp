#include <bits/stdc++.h>
using namespace std;

int n, x, a, b, c;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &x);
		if (i % 3 == 0) a += x;
		else if (i % 3 == 1) b += x;
		else c += x;
	}
	if (a > b && a > c) puts("chest");
	else if (b > a && b > c) puts("biceps");
	else puts("back");
	return 0;
}