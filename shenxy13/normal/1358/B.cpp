#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, ans = 1;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 0; i < n; ++i) {
			if (a[i] < i + 2) ans = i + 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}