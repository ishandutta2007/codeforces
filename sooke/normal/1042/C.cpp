#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 200005;

std::vector<int> vec;
int n, max, used, a[maxN], x, y, z; // x: < 0   y: = 0   z: > 0.

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] < 0) { x++; }
		else if (a[i]) { z++; }
		else { y++; }
	}
	if ((x % 2 == 0 && y == 0) || (x == 0 && z == 0)) {
		for (int i = 2; i <= n; i++) { printf("1 %d %d\n", i - 1, i); }
	} else if (x % 2 == 1 && y == 0) {
		a[0] = -maxInt;
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0 && a[max] < a[i]) { max = i; }
		}
		printf("2 %d\n", max);
		for (int i = 2; i <= n; i++) {
			if (i - 1 == max && i == 2) { continue; }
			if (i == max) { continue; }
			if (i - 1 == max) { printf("1 %d %d\n", i - 2, i); }
			else { printf("1 %d %d\n", i - 1, i); }
		}
	} else if (x % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				if (used) { printf("1 %d %d\n", used, i), used = i; }
				else { used = i; }
			}
		}
		printf("2 %d\n", used);
		used = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) { continue; }
			if (used) { printf("1 %d %d\n", used, i); used = i; }	
			else { used = i; }
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				if (used) { printf("1 %d %d\n", used, i), used = i; }
				else { used = i; }
			}
		}
		a[0] = -maxInt;
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0 && a[max] < a[i]) { max = i; }
		}
		printf("1 %d %d\n", used, max); used = max;
		if (x == 1 && z == 0) { return 0; }
		printf("2 %d\n", used);
		used = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0 || i == max) { continue; }
			if (used) { printf("1 %d %d\n", used, i); used = i; }	
			else { used = i; }
		}	
	}
	return 0;
}