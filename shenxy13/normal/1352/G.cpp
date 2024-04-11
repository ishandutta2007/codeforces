#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		if (n % 2) {
			if (n < 5) printf("-1\n");
			else if (n == 5) printf("1 3 5 2 4\n");
			else {
				for (int i = 1; i <= n; i += 2) printf("%d ", i);
				printf("%d ", n - 3);
				printf("%d ", n - 1);
				for (int i = n - 5; i > 2; i -= 2) printf("%d ", i);
				printf("2\n");
			}
		} else {
			if (n < 4) printf("-1\n");
			else if (n == 4) printf("2 4 1 3\n");
			else if (n == 6) printf("1 3 5 2 6 4\n");
			else {
				for (int i = 1; i < n; i += 2) printf("%d ", i);
				printf("%d ", n - 4);
				printf("%d ", n);
				printf("%d ", n - 2);
				for (int i = n - 6; i > 2; i -= 2) printf("%d ", i);
				printf("2\n");
			}
		}
	}
	return 0;
}