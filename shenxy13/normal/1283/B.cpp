#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", min(n, n / k * k + k / 2));
	}
	return 0;
}