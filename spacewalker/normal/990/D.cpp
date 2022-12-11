#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool ans[1000][1000];

int main() {
	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	if (a > 1 and b > 1) {
		printf("NO\n");
		return 0;
	}
	if ((n == 2 or n == 3) and a == 1 and b == 1) {
		printf("NO\n");
		return 0;
	}
	int compCount = max(a, b);
	for (int i = 0; i < n - compCount; ++i) {
		// printf("IN LOOP %d %d\n", i, i + 1);
		ans[i][i+1] = true;
		ans[i+1][i] = true;
	}
	if (b > 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) ans[i][j] = !ans[i][j];
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", (ans[i][j] ? '1' : '0'));
		}
		printf("\n");
	}
	return 0;
}