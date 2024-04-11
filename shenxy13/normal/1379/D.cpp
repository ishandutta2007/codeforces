#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<long long, int> ii;
int main() {
	int n;
	long long h, m, k, t = 0;
	scanf("%d %lld %lld %lld", &n, &h, &m, &k);
	long long H, M[2 * n], mp[n];
	for (int i = 0; i < n; ++i) scanf("%lld %lld", &H, &M[i]), mp[i] = M[i];
	int ans = n;
	sort(M, M + n);
	for (int i = 0; i < n; ++i) M[n + i] = m + M[i];
	for (int i = 0; i < n; ++i) {
		int incov1 = lower_bound(M, M + 2 * n, m + M[i]) - upper_bound(M, M + 2 * n, m + M[i] - k), incov2 = lower_bound(M, M + 2 * n, M[i] + m / 2) - upper_bound(M, M + 2 * n, M[i] + m / 2 - k);
		if (incov1 + incov2 < ans) {
			ans = incov1 + incov2;
			t = M[i];
		}
	}
	t = t % (m / 2);
	printf("%d %lld\n", ans, t);
	for (int i = 0; i < n; ++i) {
		if ((mp[i] > t - k && mp[i] < t) || (mp[i] > m + t - k && mp[i] < m + t) || (mp[i] > t + m / 2 - k && mp[i] < t + m / 2)) printf("%d ", i + 1);
	}
	return 0;
}