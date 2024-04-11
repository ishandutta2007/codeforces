#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		if (n == 1) printf("-1\n");
		else {
			printf("2");
			for (int i = 1; i < n; ++i) printf("3");
			printf("\n");
		}
	}
	return 0;
}