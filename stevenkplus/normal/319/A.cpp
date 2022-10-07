#include <cstdio>

const int MOD = 1000000007;
const int MAXN = 110;

char str[MAXN];
int N = 0;
int main() {
	scanf("%s", str);
	while (str[N]) ++N;

	int sum = 0;
	int add = 1;
	for(int i = N - 1; i >= 0; --i) {
		if (str[i] == '1') {
			(sum += add) %= MOD;
		}
		add *= 2;
		add %= MOD;
	}

	for(int i = 0; i < N - 1; ++i) {
		(sum *= 2) %= MOD;
	}

	printf("%d\n", sum);
	return 0;
}