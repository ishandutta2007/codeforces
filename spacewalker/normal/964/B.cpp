#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;
typedef long long ll;

int main() {
	int n, A, B, C, T; scanf("%d %d %d %d %d", &n, &A, &B, &C, &T);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int ti; scanf("%d", &ti);
		int maxContrib = -INF;
		for (int readTime = ti; readTime <= T; ++readTime) {
			maxContrib = max(maxContrib, A + (readTime - ti) * (C - B));
		}
		ans += maxContrib;
	}
	printf("%lld\n", ans);
	return 0;
}