#include <cstdio>

using namespace std;

const int MAXN = 1001000;

char str[MAXN];

int N, K;

bool go() {
	scanf("%d %d", &N, &K);
	if (K > N) return false;
	if (K == 1 && N > 1) return false;
	int extr = K - 2;
	if (extr < 0) extr = 0;

	int cur = 0;
	for(int i = 0; i < N - extr; ++i) {
		str[i] = 'a' + cur;
		cur = 1 - cur;
	}

	cur = 2;
	for(int i = N - extr; i < N; ++i) {
		str[i] = 'a' + cur;
		++cur;
	}

	printf("%s\n", str);
	return true;
}

int main() {
	if (!go()) {
		printf("-1\n");
	}
	return 0;
}