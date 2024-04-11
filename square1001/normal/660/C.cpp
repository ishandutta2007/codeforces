#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[300009];
int main() {
	scanf("%d %d", &n, &m);
	int ret = 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] = 1 - a[i];
	int l = 0;
	for (int i = 1; i <= n; i++) {
		if (i == n || a[i - 1] != a[i]) {
			if(a[i - 1] == 0) ret = max(ret, i - l);
			l = i;
		}
	}
	int ret2 = 0, sum = 0, r = 0;
	for (int i = 0; i < n; i++) {
		while (r < n && sum + a[r] <= m) sum += a[r], r++;
		ret2 = max(ret2, r - i); sum -= a[i];
	}
	if (ret >= ret2) {
		printf("%d\n", ret);
		for (int i = 0; i < n; i++) printf("%d ", 1 - a[i]);
	}
	else {
		printf("%d\n", ret2); r = 0;
		for (int i = 0; i < n; i++) {
			while (r < n && sum + a[r] <= m) sum += a[r], r++;
			if (r - i == ret2) {
				for (int j = 0; j < n; j++) {
					if (i <= j && j < r) printf("1 ");
					else printf("%d ", 1 - a[j]);
				}
				break;
			}
			sum -= a[i];
		}
	}
	return 0;
}