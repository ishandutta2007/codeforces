#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int q, n;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &n);
		if (n <= 4) printf("%d\n", 4 - n);
		else if (n % 2) printf("1\n");
		else printf("0\n");
	}
	return 0;
}