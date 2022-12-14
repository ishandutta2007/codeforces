#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int T, x, y;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d", &x, &y);
		if (x == 1) {
			if (y == 1) printf("YES\n");
			else printf("NO\n");
		} else if (x <= 3) {
			if (y <= 3) printf("YES\n");
			else printf("NO\n");
		} else printf("YES\n");
	}
	return 0;
}