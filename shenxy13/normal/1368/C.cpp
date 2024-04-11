#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", 3 * n + 4);
	printf("0 0\n0 1\n1 0\n1 1");
	for (int i = 1; i <= n; ++i) printf("\n%d %d\n%d %d\n%d %d", i, i + 1, i + 1, i, i + 1, i + 1);
	return 0;
}