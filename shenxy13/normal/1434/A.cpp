#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n, a[6];
	for (int i = 0; i < 6; ++i) scanf("%d", &a[i]);
	scanf("%d", &n);
	int b[n];
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	set<ii> pq;
	sort(a, a + 6);
	for (int i = 0; i < n; ++i) pq.insert(ii(b[i] - a[5], 5));
	int ans = (--pq.end()) -> first - pq.begin() -> first;
	while (true) {
		if (pq.begin() -> second == 0) break;
		ii i = *pq.begin();
		pq.erase(pq.begin());
		i.first += a[i.second] - a[i.second - 1];
		--i.second;
		pq.insert(i);
		ans = min(ans, (--pq.end()) -> first - pq.begin() -> first);
	}
	printf("%d", ans);
	return 0;
}