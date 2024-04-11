#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int d, v, l, r; scanf("%d %d %d %d", &d, &v, &l, &r);
		printf("%d\n", (d / v) - (r / v - (l-1)/v));
	}
	return 0;
}