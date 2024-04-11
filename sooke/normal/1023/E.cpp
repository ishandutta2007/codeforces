#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

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

std::string s = "", t = "", ans;
int n, x, y;

inline bool query(int a, int b, int c, int d) {
	std::cout << "? " << a << " " << b << " " << c << " " << d << std::endl;
	std::cin >> ans;
	if (ans[0] == 'Y') {
		return true;
	} else {
		return false;
	}
}

int main() {
	std::cin >> n;
	x = y = 1;
	for (int i = 1; i <= n - 1; i++) {
		if (y <= n - 1 && query(x, y + 1, n, n)) {
			s = s + "R";
			y++;
		} else {
			s = s + "D";
			x++;
		}
	}
	x = y = n;
	for (int i = 1; i <= n - 1; i++) {
		if (x >= 2 && query(1, 1, x - 1, y)) {
			t = "D" + t;
			x--;
		} else {
			t = "R" + t;
			y--;
		}
	}
	std::cout << "! " << s + t << std::endl;
	return 0;
}

// By Sooke.
// CF1023E Down or Right.