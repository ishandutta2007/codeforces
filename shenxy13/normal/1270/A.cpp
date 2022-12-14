#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int x, k1, k2, a1 = 0, a2 = 0;
		scanf("%d %d %d", &x, &k1, &k2);
		for (int i = 0; i < k1; ++i) {
			scanf("%d", &x);
			a1 = max(a1, x);
		}
		for (int i = 0; i < k2; ++i) {
			scanf("%d", &x);
			a2 = max(a2, x);
		}
		if (a1 > a2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}