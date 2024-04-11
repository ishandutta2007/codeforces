#include <cstdio>

using namespace std;

char buf[12345678];

int main() {
	int N;
	scanf("%d", &N);
	if (N <= 3) {
		if (N < 3) {
			printf("-1\n");
		} else {
			printf("210\n");
		}
		return 0;
	}
	int curmod = 1;
	for(int i = 1; i < N; ++i) {
		curmod = curmod * 10 % 21;
	}
	int x = 0;
	while ((x * 10 + curmod) % 21 != 0) {
		x++;
	}
	for(int i = 1; i < N; ++i) {
		buf[i] = '0';
	}
	sprintf(buf + N - 4, "%04d", x * 10);
	buf[0] = '1';
	printf("%s\n", buf);
	return 0;
}