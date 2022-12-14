#include <cstdio>
#include <algorithm>

using namespace std;

#define N 200005

int a[N];

main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int rlt = 1 << 30;
	for (int i = 1; i <= n / 2; i ++) {
		if (rlt > a[i + n / 2] - a[i]) rlt = a[i + n / 2] - a[i];
	}
	printf("%d\n", rlt);
}