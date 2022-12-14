#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", min(n / k, m) - max(0, (m - n / k + k - 2) / (k - 1)));
	}
	return 0;
}