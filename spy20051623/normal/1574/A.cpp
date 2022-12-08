#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) putchar('(');
		for (int j = 0; j < i; ++j) putchar(')');
		for (int j = 0; j < n - i; ++j) printf("()");
		puts("");
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}