#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t, n, x, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d %d %d", &n, &x, &a, &b);
		printf("%d\n", min(n - 1, x + abs(b - a)));
	}
	return 0;
}