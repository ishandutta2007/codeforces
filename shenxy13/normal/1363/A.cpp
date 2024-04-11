#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, x, a, e = 0, o = 0;
		scanf("%d %d", &n, &x);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a);
			if (a % 2) ++o;
			else ++e;
		}
		if (x % 2) {
			if (o != 0) {
				--o, --x;
				if (e / 2 * 2 + o / 2 * 2 >= x) printf("Yes\n");
				else printf("No\n");
			} else printf("No\n");
		} else {
			if (o != 0 && e != 0) {
				--o, --e, x -= 2;
				if (e / 2 * 2 + o / 2 * 2 >= x) printf("Yes\n");
				else printf("No\n");
			} else printf("No\n");
		}
	}
	return 0;
}