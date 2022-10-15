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

std::string s;
int n, p, cur, ans;

int main() {
	std::cin >> s;
	p = s.size();
	s = s + s;
	n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] != s[i]) {
			cur++;
		} else {
			cur = 1;
		}
		ans = std::max(ans, cur);
	}
	std::cout << std::min(ans, p);
	return 0;
}

// By Sooke.
// CF1025C Plasticine zebra.