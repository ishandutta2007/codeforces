#include <cstdio>
#include <algorithm>

using namespace std;

int ar[11][11];

int main() {
	int ans = 0;
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1)
				ans = abs(3 - i) + abs(3 - j);
		}
	}
	printf("%d\n", ans);
	return 0;
}