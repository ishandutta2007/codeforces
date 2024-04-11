#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		if (a[0] == a[n - 1]) printf("%d\n", n);
		else printf("1\n");
	}
	return 0;
}