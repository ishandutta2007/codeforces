#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

int n, a[310], b[310];

void f() {
	forn (i, n) {
		if (b[i] < a[i]) {
			putchar('P');
			++b[i];
		}
		if (i < n - 1) {
			putchar('R');
		}
	}
	forn (i, n - 1) {
		putchar('L');
	}
}

int main() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		b[i] = 0;
	}
	forn (i, 310) {
		f();
	}
}