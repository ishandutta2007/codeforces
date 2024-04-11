#include <cstdio>
#define Maxn 100005
#define Inf 2147483647

inline int read() {
	char c = getchar();
	int n = 0;
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return n;
}

int n, _min = Inf, a[Maxn];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read() + 1 - i;
		if (a[i] <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		a[i] = (a[i] - 1) / n + 1;
		if (_min > a[i]) {
			_min = a[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (_min == a[i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}

// By Sooke.
// CF996B World Cup.