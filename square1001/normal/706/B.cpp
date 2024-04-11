#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[100009], q, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &x);
		int ret = lower_bound(a, a + n, x + 1) - a;
		printf("%d\n", ret);
	}
	return 0;
}