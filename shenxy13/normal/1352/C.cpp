#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", (k - 1) / (n - 1) * n + (k - 1) % (n - 1) + 1);
	}
	return 0;
}