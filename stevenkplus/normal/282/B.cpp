#include <cstdio>

using namespace std;

int N;
int main() {

	scanf("%d", &N);
	int sum = 0;
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (sum + a <= 500) {
			printf("A");
			sum += a;
		} else {
			printf("G");
			sum -= b;
		}
	}
	printf("\n");
	return 0;
}