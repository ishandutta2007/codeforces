#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	char s[100];
	int r[30];
	memset(r, 0, sizeof r);
	getchar();
	gets(s);
	r[s[0] - 'A'] = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			if (!r[s[i] - 'A'])
				r[s[i] - 'A'] = 1;
			else {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
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