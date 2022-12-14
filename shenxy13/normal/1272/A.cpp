#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int q, a, b, c;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", max(0, (max(a - 1, max(b - 1, c - 1)) - min(a + 1, min(b + 1, c + 1))) * 2));
	}
	return 0;
}