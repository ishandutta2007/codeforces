#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i != n - 1) printf("B");
				else printf(j == 0 ? "B" : "W");
			}
			printf("\n");
		}
	}
	return 0;
}