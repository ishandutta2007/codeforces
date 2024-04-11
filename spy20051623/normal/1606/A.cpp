#include <bits/stdc++.h>

using namespace std;

char s[500];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	s[n - 1] = s[0];
	printf("%s\n", s);
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