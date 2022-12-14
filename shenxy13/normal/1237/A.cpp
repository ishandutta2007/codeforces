#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n], cnt = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2) {
			if (cnt % 2) {
				if (a[i] > 0) printf("%d\n", a[i] / 2 + 1);
				else printf("%d\n", a[i] / 2);
			} else {
				if (a[i] > 0) printf("%d\n", a[i] / 2);
				else printf("%d\n", a[i] / 2 - 1);
			}
			cnt += 1;
		} else printf("%d\n", a[i] / 2);
	}
	return 0;
}