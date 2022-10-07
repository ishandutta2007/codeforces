#include <cstdio>

using namespace std;

int calc(int a, int b) {
	if (a == 0) {
		return 0;
	}
	return b / a + calc(b % a, a);
}

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = calc(a, b);
		printf("%d\n", ans);
	}

	return 0;
}