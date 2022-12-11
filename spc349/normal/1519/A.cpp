#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int x, y, d; scanf("%d%d%d", &x, &y, &d);
		if (x > y) swap(x, y);
		if (y <= 1ll * x * (d + 1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}