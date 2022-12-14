#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int b, pmax = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b);
		printf("%d ", pmax + b);
		if (b > 0) pmax += b;
	}
	return 0;
}