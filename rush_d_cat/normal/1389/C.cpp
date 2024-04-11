#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int t, n;
char s[N];
int chk(char x, char y) {
	bool f = 0; int len = 0;
	for (int i = 1; i <= n; i ++) {
		if (f == 0) {
			if (s[i] == x) {
				len ++; f ^= 1;
			}
		} else {
			if (s[i] == y) {
				len ++; f ^= 1;
			}
		}
	}
	if (x != y && len % 2 == 1) len --; 
	return n - len;
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		int ans = 1e9;
		for (char c = '0'; c <= '9'; c ++) {
			for (char d = '0'; d <= '9'; d ++) {
				ans = min(ans, chk(c, d));
			}
		}
		printf("%d\n", ans);
	}
}