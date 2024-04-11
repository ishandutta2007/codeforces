#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	if (n == 1) puts("-1");
	else printf("%d %d %d\n", n, n + 1, n * (n + 1));
	return 0;
}