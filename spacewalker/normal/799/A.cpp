#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n, t, k, d;
	scanf("%d %d %d %d", &n, &t, &k, &d);
	int c1time = ceil(n / (double)k) * t;
	int c2activetime = c1time - d;
	if (c2activetime <= 0) {
		printf("NO\n");
		return 0;
	} else {
		// will we be able to bake a positive number of cakes?
		printf("%s\n", (c1time - d > t ? "YES" : "NO"));
		return 0;
	}
}