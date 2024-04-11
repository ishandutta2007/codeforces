#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	if (r == 1 && c == 1) {
		printf("0");
		return 0;
	} else if (r == 1) {
		for (int i = 1; i <= c; ++i) printf("%d ", i + 1);
		return 0;
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (j != c) printf("%d ", (c + i) * j);
			else printf("%d\n", (c + i) * j);
		}
	}
	return 0;
}