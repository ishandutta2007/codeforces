#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k1, k2; scanf("%d %d %d", &n, &k1, &k2);
		int amax = 0, bmax = 0;
		for (int i = 0; i < k1; ++i) {
			scanf("%d", &n);
			amax = max(amax, n);
		}
		for (int i = 0; i < k2; ++i) {
			scanf("%d", &n);
			bmax = max(bmax, n);
		}
		if (amax > bmax) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}