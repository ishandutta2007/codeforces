#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;

int t, n;
std::string s;

inline bool check() {
	for (int i = 0; i < n; i++) {
		if (std::abs(s[i] - s[n - 1 - i]) != 0 && std::abs(s[i] - s[n - 1 - i]) != 2) {
			return false;
		}
	}
	return true;
}

int main() {
	t = read();
	for (int i = 1; i <= t; i++) {
		n = read();
		std::cin >> s;
		if (check()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

// By Sooke.
// CF1027A Palindromic Twist.