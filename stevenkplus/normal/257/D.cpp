#include <cstdio>

using namespace std;

const int MAXN = 100100;
int ar[MAXN];
bool ans[MAXN];
char str[MAXN];

int N;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	int sum = 0;
	for(int i = N - 1; i >= 0; --i) {
		if (sum < 0) {
			ans[i] = true;
			sum += ar[i];
		} else {
			ans[i] = false;
			sum -= ar[i];
		}
	}
	if (sum < 0) {
		sum *= -1;
		for(int i = 0; i < N; ++i) {
			ans[i] = !ans[i];
		}
	}

	for(int i = 0; i < N; ++i) {
		if (ans[i]) {
			str[i] = '+';
		} else {
			str[i] = '-';
		}
	}

	printf("%s\n", str);
	return 0;
}