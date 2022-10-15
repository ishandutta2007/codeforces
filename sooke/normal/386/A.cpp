#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxN = 1005;

int n;
std::pair<int, int> a[maxN];

int main() {
	n = read();
	for (int i = 1; i <= n; i++) { a[i] = std::make_pair(-read(), i); }
	std::sort(a + 1, a + n + 1);
	printf("%d %d\n", a[1].second, -a[2].first);
	return 0;
}

// By Sooke.
// CF386A Second-Price Auction.