#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, mod = 0;
	scanf("%d", &n);
	char c1, c2, ans[n];
	for (int i = 0; i <= (n - 1) / 2; ++i) {
		scanf(" %c %c", &c1, &c2);
		if (c1 != c2) {
			ans[2 * i] = c1;
			ans[2 * i + 1] = c2;
		} else {
			if (c2 == 'a') c1 = 'b';
			else c1 = 'a';
			ans[2 * i] = c1;
			ans[2 * i + 1] = c2;
			++mod;
		}
	}
	printf("%d\n", mod);
	for (int i = 0; i < n; ++i) printf("%c", ans[i]);
	return 0;
}