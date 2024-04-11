#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", (n * m + 1) / 2);
	}
	return 0;
}