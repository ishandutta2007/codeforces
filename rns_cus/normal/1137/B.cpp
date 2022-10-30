#include <bits/stdc++.h>
using namespace std;

#define N 500500

char s[N], t[N];
int h[N], m, n, x, y;
void make_PI() {
    int k = 0;
    m = strlen(t);
    h[1] = 0;
    for (int i = 2; i <= m; i ++) {
        while (k && t[k] != t[i - 1]) k = h[k];
        if (t[k] == t[i - 1]) k ++;
        h[i] = k;
    }
}

int main() {
    scanf("%s %s", s, t);
    make_PI();
    n = strlen(s);
    for (int i = 0; i < n; i ++)
		(s[i] == '0' ? x : y) ++;
	bool fg = 0;
	for (int i = 0, j = 0; i < n; i ++, j ++) {
		if (fg) {
			if (x) putchar('0'), x --;
			else putchar('1'), y --;
			continue;
		}
		if (j == m) j = h[j];
		if (j < m) {
			if (t[j] == '0') {
				if (x) putchar('0'), x --;
				else putchar('1'), y --, fg = 1;
			}
			else {
				if (y) putchar('1'), y --;
				else putchar('0'), x --, fg = 1;
			}
		}
	}

    return 0;
}