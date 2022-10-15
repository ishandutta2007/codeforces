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

#define MAXN 100005

string s;
int n, cnt, a[MAXN];

int main() {
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] ^ 48;
		if (a[i] == 1) {
			cnt++;	
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) {
			if (a[i] == 2 && cnt > 0) {
				for (int j = 1; j <= cnt; j++) {
					printf("1");
				}
				cnt = 0;
			}
			printf("%d", a[i]);
		}
	}
	if (cnt > 0) {
		for (int j = 1; j <= cnt; j++) {
			printf("1");
		}
	}
	printf("\n");
	return 0;
}

// By Sooke.
// CF1009B Minimum Ternary String.