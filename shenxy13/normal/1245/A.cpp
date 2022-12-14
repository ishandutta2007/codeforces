#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (gcd(a, b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}