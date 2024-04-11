#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, a, b, c, d, k;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		a += c - 1;
		b += d - 1;
		if (a / c + b / d <= k) printf("%d %d\n", a / c, b / d);
		else printf("-1\n");
	}
	return 0;
}