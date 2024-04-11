#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", max(2 * min(a, b), max(a, b)) * max(2 * min(a, b), max(a, b)));
	}
}