#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, a, b;
		scanf("%d", &n);
		long long w[n], ans[n - 1];
		ans[n - 2] = 0;
		for (int i = 0; i < n; ++i) scanf("%lld", &w[i]);
		multiset<long long> ms;
		for (int i = 1; i < n; ++i) {
			scanf("%d %d", &a, &b);
			ans[n - 2] += w[a - 1] + w[b - 1];
			ms.insert(w[a - 1]);
			ms.insert(w[b - 1]);
		}
		for (int i = 0; i < n; ++i) ms.erase(ms.find(w[i]));
		for (int i = n - 3; i >= 0; --i) {
			ans[i] = ans[i + 1] - *ms.begin();
			ms.erase(ms.begin());
		}
		printf("%lld", ans[0]);
		for (int i = 1; i < n - 1; ++i) printf(" %lld", ans[i]);
		printf("\n");
	}
	return 0;
}