#include <bits/stdc++.h>
using namespace std;

#define N 30303

char s[N];

int main() {
	int n;
	scanf("%d\n", &n);
	gets(s);
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'R') r ++;
		else if (s[i] == 'G') g ++;
		else b ++;
	}
	if (g > 0 && r > 0 && b > 0) {
		puts("BGR");
		return 0;
	}
    if (g == 0 && r == 0) {
		puts("B");
		return 0;
    }
    if (r == 0 && b == 0) {
		puts("G");
		return 0;
    }
    if (b == 0 && g == 0) {
		puts("R");
		return 0;
    }
    if (r == 0) {
        if (g == 1) {
			if (b == 1) puts("R");
			else puts("GR");
		}
		else {
			if (b == 1) puts("BR");
			else puts("BGR");
		}
		return 0;
    }
    if (g == 0) {
		if (b == 1) {
			if (r == 1) puts("G");
			else puts("BG");
		}
		else {
			if (r == 1) puts("GR");
			else puts("BGR");
		}
		return 0;
    }
    if (b == 0) {
		if (r == 1) {
			if (g == 1) puts("B");
			else puts("BR");
		}
		else {
			if (g == 1) puts("BG");
			else puts("BGR");
		}
		return 0;
    }
    assert(0);

	return 0;
}