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

string s;
int n;

inline bool isRomaji(char c) {
	if (c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e') {
		return true;
	}
	return false;
}
inline bool check() {
	for (int i = 2; i <= n; i++) {
		if (isRomaji(s[i - 1])) {
			continue;
		} else if (s[i - 1] == 'n') {
			continue;
		} else if (isRomaji(s[i])) {
			continue;
		}
		return false;
	}
	return isRomaji(s[n]) || s[n] == 'n';
}

int main() {
	cin >> s;
	n = s.size();
	s = " " + s;
	if (check()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

// By Sooke.