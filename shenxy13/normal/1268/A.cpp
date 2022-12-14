#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", n);
	char a[n], b[k];
	for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);
	int g = -1;
	for (int i = 0; i < n; ++i) {
		if (i < k) b[i] = a[i];
		if (b[i % k] < a[i] && g == -1) g = 0;
		else if (b[i % k] > a[i] && g == -1) g = 1;
	}
	if (g) {
		for (int i = 0; i < n; ++i) printf("%c", b[i % k]);
	} else {
		for (int i = k - 1; i >= 0; --i) {
			if (b[i] != '9') {
				for (int j = 0; j < n; ++j) {
					if (j % k == i) printf("%c", b[j % k] + 1);
					else printf("%c", b[j % k]);
				}
				return 0;
			} else b[i] = '0';
		}
	}
	return 0;
}