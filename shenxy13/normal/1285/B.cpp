#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 1000000007;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		long long a[n + 1];
		a[0] = 0;
		for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
		long long sum = a[n], msum = max(0LL, a[1]);
		for (int i = 2; i < n; ++i) {
			msum = max(msum, a[i] - min(0LL, a[i - 1]));
			a[i] = min(a[i - 1], a[i]);
		}
		msum = max(msum, a[n] - a[n - 1]);
		if (sum > msum) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}