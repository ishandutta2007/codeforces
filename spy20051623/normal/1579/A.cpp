#include <bits/stdc++.h>

using namespace std;

char s[55];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') ++b;
		else ++a;
	}
	if (a == b) printf("YES\n");
	else printf("NO\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}