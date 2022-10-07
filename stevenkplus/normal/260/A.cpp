#include <cstdio>

using namespace std;

int lengthen(int a, int b) {
	for(int i = 0; i < 10; ++i) {
		int k = i + a * 10;
		if (k % b == 0) {
			return k;
		}
	}
	return -1;
}
int a, b, n;
int main () {
	scanf("%d %d %d", &a, &b, &n);
	int k = lengthen(a, b);
	if (k == -1) printf("-1\n");
	else {
		printf("%d", k);
		for(int i = 1; i < n; ++i) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}