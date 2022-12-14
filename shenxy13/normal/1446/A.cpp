#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<long long, int> ii;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		long long W;
		scanf("%d %lld", &n, &W);
		ii w[n];
		long long p[n];
		for (int i = 0; i < n; ++i) scanf("%lld", &w[i].first), w[i].second = i + 1;
		sort(w, w + n);
		p[0] = w[0].first;
		for (int i = 1; i < n; ++i) p[i] = p[i - 1] + w[i].first;
		for (int i = 0; i < n; ++i) {
			if (p[i] >= (W + 1) / 2 && p[i] <= W) {
				printf("%d\n", i + 1);
				printf("%d", w[0].second);
				for (int j = 1; j <= i; ++j) printf(" %d", w[j].second);
				printf("\n");
				break;
			} else if (w[i].first >= (W + 1) / 2 && w[i].first <= W) {
				printf("1\n%d\n", w[i].second);
				break;
			} else if (w[i].first > W) {
				printf("-1\n");
				break;
			} else if (i == n - 1) {
				printf("-1\n");
				break;
			}
		}
	}
	return 0;
}