#include <cstdio>

using namespace std;

int nextFactor(int n, int pref) {
	int x = pref;
	if (x > n) return n;
	while (x * x <= n) {
		if (n % x == 0) {
			return x;
		}
		x++;
	}
	if (x * x > n) {
		return n;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	int prf = 2;
	sum += n;
	while (n > 1) {
		int f = nextFactor(n, prf);
		n /= f;
		prf = f;
		sum += n;
	}
	printf("%d\n", sum);
	return 0;
}