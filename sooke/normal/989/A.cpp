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
char opt[4];
int n;

int main() {
	cin >> s;
	n = s.size();
	s = " " + s;
	for (int i = 3; i <= n; i++) {
		opt[1] = s[i - 2];
		opt[2] = s[i - 1];
		opt[3] = s[i];
		sort(opt + 1, opt + 3 + 1);
		if (opt[1] == 'A' && opt[2] == 'B' && opt[3] == 'C') {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

// By Sooke.
// CF989A A Blend of Springtime.