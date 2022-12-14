#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 200010

int a[N], d[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		d[i] = n;
	}
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 0) {
			d[i] = 0;
			for (int j = i + 1; j <= n && a[j]; j ++) d[j] = min(d[j], j - i);
			for (int j = i - 1; j && a[j]; j --) d[j] = min(d[j], i - j);
		}
	}
	for (int i = 1; i < n; i ++) printf("%d ", d[i]);
	printf("%d\n", d[n]);
    return 0;
}