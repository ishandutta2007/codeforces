#include <bits/stdc++.h>
using namespace std;

int n;
char s[1001001];

void solve(int x) {
	if (x == n) {
		printf("%d\n", x); return;
	}
	if (s[x] == 'l') {
		solve(x + 1);
		printf("%d\n", x);
	}
	else {
		printf("%d\n", x);
		solve(x + 1);
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	solve(1);
	return 0;
}