#include <cstdio>

const int f[6] = {0, 100, 20, 10, 5, 1};

int n, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 5; i++) {
		ans += n / f[i]; 
		n -= n / f[i] * f[i];
	}
	printf("%d", ans);
	return 0;
}

// By Sooke.
// CF996A Hit the Lottery.