#include <cstdio>

#define Maxn 260
#define Inf 2147483647

#define Min(x, y) ((x) < (y) ? (x) : (y))
#define Max(x, y) ((x) > (y) ? (x) : (y))

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

int n, m, tag[Maxn];

int main() {
	n = read() , m = read();
	for (int i = 1, j; i <= n; i++) {
		int t = read() + 1;
		if (tag[t] == 0) {
			int res = Inf, s;
			for (j = Max(t + 1 - m, 1); j <= t; j++) {
				if (t - tag[j] + 1 <= m && tag[j] != 0) {
					if (res > tag[j]) {
						res = tag[j];
						s = j;
					}
				}
			}
			if (res == Inf) {
				for (j = Max(t + 1 - m, 1); j <= t; j++) {
					if (tag[j] == 0) {
						if (res > j) {
							res = j;
							s = j;
						}
					}
				}	
			}
			for (j = s; j <= t; j++) {
				tag[j] = res;
			}
		}
		if (i == n) {
			printf("%d\n", tag[t] - 1);
		} else {
			printf("%d ", tag[t] - 1);
		}
	}
	return 0;
}

// By Sooke.
// CF980C Posterized.