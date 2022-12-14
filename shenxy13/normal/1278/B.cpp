#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b) swap(a, b);
		int j = 0;
		while (a > b) b += ++j;
		while ((b - a) % 2) b += ++j;
		printf("%d\n", j);
	}
	return 0;
}