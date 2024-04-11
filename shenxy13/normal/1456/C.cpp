#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long c[n], sum = 0, msum = 0, ans = -8000000000000000000;
	for (int i = 0; i < n; ++i) scanf("%lld", &c[i]);
	sort(c, c + n);
	for (int i = 0; i < n; ++i) sum += c[i];
	for (int i = 0; i < n; ++i) msum += i * c[i];
	ans = max(ans, msum);
	int freq[k + 1];
	fill_n(freq, k + 1, 0);
	for (int i = 0; i < n; ++i) {
		sum -= c[i];
		if (i % (k + 1)) {
			msum -= sum;
			msum += c[i] * (freq[i % (k + 1)] - freq[0]);
		}
		++freq[i % (k + 1)];
		ans = max(ans, msum);
	}
	printf("%lld", ans);
	return 0;
}