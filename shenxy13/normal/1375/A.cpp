#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) {
			if (i % 2) printf("%d ", -abs(a[i]));
			else printf("%d ", abs(a[i]));
		}
		printf("\n");
	}
	return 0;
}