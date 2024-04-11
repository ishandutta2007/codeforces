#include <bits/stdc++.h>
using namespace std;

#define N 100010

int x, y, n;

void move(char ch) {
	if (ch == 'L') x --;
	if (ch == 'R') x ++;
	if (ch == 'U') y ++;
	if (ch == 'D') y --;
}

char s[N];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		x = 0, y = 0;
		for (int j = i; j < n; j ++) {
			move(s[j]);
			if (x == 0 && y == 0) ans ++;
		}
	}
	cout << ans << endl;
}