#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

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
const int maxN = 1000005;

std::vector<int> vc;
int tn, n, ansx, ansy, a[maxN], cnt[maxN];
double min;

int main() {
	tn = read();
	for (; tn >= 1; tn--) {
		n = read();
		min = maxLongLong;
		vc.clear();
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			cnt[a[i]]++;
			if (cnt[a[i]] == 2) {
				vc.push_back(a[i]);
			}
			if (cnt[a[i]] == 4) {
				min = 0.0;
				ansx = a[i];
				ansy = a[i];
			}
		}
		std::sort(vc.begin(), vc.end());
		for (int i = 1; i < vc.size(); i++) {
			int x = vc[i - 1], y = vc[i];
			if (min > (double)(x + y) * (x + y) / x / y) {
				min = (double)(x + y) * (x + y) / x / y;
				ansx = x;
				ansy = y;
			}
		}
		std::cout << ansx << " " << ansy << " " << ansx << " " << ansy << std::endl;
		for (int i = 1; i <= n; i++) {
			cnt[a[i]]--;
		}
	}
	return 0;
}

// By Sooke.
// CF1027C Minimum Value Rectangle.