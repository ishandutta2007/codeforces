#include <bits/stdc++.h>

using namespace std;

char s[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n - 2; ++i) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
			++cnt;
		}
	}
	while (m--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		if (s[x] == 'a') {
			if (x <= n - 2 && s[x + 1] == 'b' && s[x + 2] == 'c') {
				--cnt;
			}
		}
		if (s[x] == 'b') {
			if (x <= n - 1 && x >= 2 && s[x - 1] == 'a' && s[x + 1] == 'c') {
				--cnt;
			}
		}
		if (s[x] == 'c') {
			if (x >= 3 && s[x - 2] == 'a' && s[x - 1] == 'b') {
				--cnt;
			}
		}
		if (c == 'a') {
			if (x <= n - 2 && s[x + 1] == 'b' && s[x + 2] == 'c') {
				++cnt;
			}
		}
		if (c == 'b') {
			if (x <= n - 1 && x >= 2 && s[x - 1] == 'a' && s[x + 1] == 'c') {
				++cnt;
			}
		}
		if (c == 'c') {
			if (x >= 3 && s[x - 2] == 'a' && s[x - 1] == 'b') {
				++cnt;
			}
		}
		printf("%d\n", cnt);
		s[x] = c;
	}
	return 0;
}