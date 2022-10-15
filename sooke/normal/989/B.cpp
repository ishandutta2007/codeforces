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

int n, m;
bool flag = false;
string s;

int main() {
	n = read(), m = read();
	cin >> s;
	s = " " + s;
	for (int i = m + 1; i <= n; i++) {
		if (s[i - m] == '0' && s[i] == '0') {
			
		} else if (s[i - m] == '1' && s[i] == '1') {
			
		} else if (s[i - m] == '0' && s[i] == '1') {
			flag = true;
		} else if (s[i - m] == '1' && s[i] == '0') {
			flag = true;
		} else if (s[i - m] == '.' && s[i] == '.') {
			flag = true;
			s[i - m] = '0';
			s[i] = '1';
		} else if (s[i - m] == '.' && s[i] != '.') {
			flag = true;
			s[i - m] = s[i] ^ 1;
		} else if (s[i - m] != '.' && s[i] == '.') {
			flag = true;
			s[i] = s[i - m] ^ 1;
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == '.') {
				s[i] = '0';
			}
			putchar(s[i]);
		}
		printf("\n");
	} else {
		printf("No\n");
	}
	return 0;
}

// By Sooke.
// CF989B A Tide of Riverscape.