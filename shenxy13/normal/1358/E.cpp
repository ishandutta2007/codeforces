#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n;
	scanf("%d", &n);
	long long a[(n + 1) / 2], x;
	for (int i = 0; i < (n + 1) / 2; ++i) scanf("%lld", &a[i]);
	for (int i = (n + 1) / 2 - 2; i >= 0; --i) a[i] += a[i + 1];
	scanf("%lld", &x);
	if (x >= 0) printf("%d", a[0] + n / 2 * x > 0 ? n : -1);
	else {
		long long ans = n + 1;
		for (int i = 0; i < (n + 1) / 2; ++i) {
			if (ans <= n && i + ans > n) break;
			ans = min(ans, a[i] > 0 ? (min((a[i] - 1) / -x, (long long) n / 2) + (n + 1) / 2 - i) : -1);
		}
		if (ans <= n / 2) printf("-1");
		else printf("%lld", ans);
	}
	return 0;
}