#include <cstdio>

using namespace std;

const int MAXN = 10010;

int K, A, B;

char str[MAXN];

int main() {
	scanf("%d %d %d", &K, &A, &B);
	scanf("%s", str);

	int len = 0;
	while (str[len]) ++len;

	int av = len / K;
	int rem = len % K;
	int top = av;
	if (rem) ++top;
	int cur = 0;

	if (av < A || top > B) {
		printf("No solution\n");
	} else {
		for(int i = 0; i < rem; ++i) {
			for(int j = 0; j < av + 1; ++j) {
				printf("%c", str[cur]);
				++cur;
			}
			printf("\n");
		}
		for(int i = rem; i < K; ++i) {
			for(int j = 0; j < av; ++j) {
				printf("%c", str[cur]);
				++cur;
			}
			printf("\n");
		}
	}

	return 0;
}