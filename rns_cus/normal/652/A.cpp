#include <bits/stdc++.h>
using namespace std;

long long h1, h2, a, b, H;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%I64d %I64d %I64d %I64d", &h1, &h2, &a, &b);
	H = h1;
	for (int d = 0; d < 1000000; d ++) {
		if (!d) H += a * 8;
		else H += a * 12;
		if (H >= h2) {
			printf("%d\n", d); return 0;
		}
		H -= 12 * b;
	}
	puts("-1");
	return 0;
}