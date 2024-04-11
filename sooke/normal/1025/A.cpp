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
int n, cnt[1000];

inline bool check() {
	for (int i = 'a'; i <= 'z'; i++) {
		if (cnt[i] >= 2) {
			return true;
		}
	}
	return false;
}

int main() {
	n = read();
	if (n == 1) {
		printf("Yes\n");
		return 0;
	}
	std::cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		cnt[s[i]]++;
	}
	if (check()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}

// By Sooke.
// CF1025A Doggo Recoloring.