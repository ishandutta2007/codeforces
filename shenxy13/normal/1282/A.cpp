#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b, c, r;
		scanf("%d %d %d %d", &a, &b, &c, &r);
		if (a > b) swap(a, b);
		if (b <= c - r) printf("%d\n", b - a);
		else if (b <= c + r) printf("%d\n", max(c - r - a, 0));
		else if (a <= c + r) printf("%d\n", max(b - c - r, 0) + max(c - r - a, 0));
		else printf("%d\n", b - a);
	}
}