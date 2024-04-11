#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

int n, m, mul, tmp, ans;
string a, b;
char u, v, x, y;

int main() {
	n = read();
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	if (n % 2 == 1) {
		ans += a[n / 2 + 1] != b[n / 2 + 1];
	}
	for (int i = 1; i <= n / 2; i++) {
		u = a[i];
		v = a[n + 1 - i];
		x = b[i];
		y = b[n + 1 - i];
		if (u == v) {
			if (x == y) {
				ans += 0;
			} else if (x != y) {
				if (u == x || u == y) {
					ans += 1;
				} else {
					ans += 2;
				}
			}
		} else {
			if (x == y) {
				if (u == x || v == x) {
					ans += 1;
				} else {
					ans += 1;
				}
			} else {
				if (u == x && v == y) {
					ans += 0;
				} else if (u == y && v == x) {
					ans += 0;
				} else {
					if (u == x || u == y || v == x || v == y) {
						ans += 1;
					} else {
						ans += 2;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}