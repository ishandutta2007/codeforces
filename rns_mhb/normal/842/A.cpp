#include <bits/stdc++.h>
using namespace std;

int l, r, x, y, k;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
	for (int b = x; b <= y; b ++) {
		long long a = 1ll * b * k;
		if (l <= a && a <= r) return puts("YES"), 0;
	}
	puts("NO");
	return 0;
}