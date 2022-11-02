#include <cstdio>
#define getchar_unlocked getchar
#define putchar_unlocked putchar
void reader(int *x) {
	int k = getchar_unlocked(); *x = k - '0';
	while (1) {
		k = getchar_unlocked();
		if (k < '0' || k > '9') break;
		*x = ((*x) << 1) + ((*x) << 3) + k - '0';
	}
}
inline void writer(int x) {
	int s = 0, p; char f[13];
	while (x) {
		p = x; x /= 10;
		f[s++] = p - (x << 1) - (x << 3);
	}
	if (!s) f[s++] = 0;
	while (s--) putchar_unlocked(f[s] + '0');
}
int n, a[100009], r[100009];
int main() {
	reader(&n);
	for (int i = 0; i < n; i++) reader(&a[i]);
	int x = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > x) r[i] = x + 1, x = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (r[i]) {
			for (int j = a[i]; j >= r[i]; j--) {
				if (j != a[i]) putchar_unlocked(' ');
				writer(j);
			}
		}
		putchar_unlocked('\n');
	}
	return 0;
}