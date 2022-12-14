#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 1; i < n; ++i) {
			if (abs(a[i] - a[i - 1]) > 1) {
				printf("YES\n%d %d\n", i, i + 1);
				goto hell;
			}
		}
		printf("NO\n");
		hell:;
	}
	return 0;
}