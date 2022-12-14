#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, d, e;
	scanf("%d %d %d", &n, &d, &e);
	e *= 5;
	int ans = n;
	for (int i = 0; i <= n; i += e) ans = min(ans, (n - i) % d);
	printf("%d", ans);
	return 0;
}