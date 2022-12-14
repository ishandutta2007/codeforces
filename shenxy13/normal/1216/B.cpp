#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	pair<int, int> a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i].first);
	for (int i = 0; i < n; ++i) a[i].second = i;
	sort(a, a + n, greater< pair<int, int> >());
	for (int i = 0; i < n; ++i) ans += (a[i].first * i + 1);
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) printf("%d ", a[i].second + 1);
	return 0;
}