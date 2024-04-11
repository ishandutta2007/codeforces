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

std::string s, t;

int main() {
	std::cin >> s >> t;
	std::sort(s.begin(), s.end());
	if (s[0] == '0') {
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != '0') {
				std::swap(s[0], s[i]);
				break;
			}
		}
	}
	if (s == t) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "WRONG_ANSWER" << std::endl;
	}
	return 0;
}

// By Sooke.
// CF12B Correct Solution?