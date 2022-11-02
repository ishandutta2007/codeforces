#include <bits/stdc++.h>
using namespace std;

const char t[10] = "v<^>";

int n, p[10];
char s[10];

int main() {
	scanf("%c %c", &s[0], &s[1]);
	scanf("%d", &n);
	n %= 4;
	if (n % 2 == 0) puts("undefined");
	else {
		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 4; j ++) {
				if (s[i] == t[j]) {
					p[i] = j;
					break;
				}
			}
		}
		if ((p[1] - p[0] + 8 - n) % 4 == 0) puts("cw");
		else puts("ccw");
	}
}