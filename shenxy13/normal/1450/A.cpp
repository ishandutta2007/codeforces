#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		char a[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &a[i]);
		sort(a, a + n);
		for (int i = 0; i < n; ++i) printf("%c", a[i]);
		printf("\n");
	}
	return 0;
}