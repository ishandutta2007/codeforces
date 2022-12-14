#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int b, g, n, ans = 0;
	scanf("%d %d %d", &b, &g, &n);
	for (int i = 0; i <= n; i++) {
		if (b >= i && g >= n - i) ans += 1;
	}
	printf("%d", ans);
	return 0;
}