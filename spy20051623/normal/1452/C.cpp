#include <bits/stdc++.h>

using namespace std;

char s[200005];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int a = 0, b = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			++a;
		if (s[i] == ')' && a) {
			--a;
			++ans;
		}
		if (s[i] == '[')
			++b;
		if (s[i] == ']' && b) {
			--b;
			++ans;
		}
	}
	printf("%d\n", ans);
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