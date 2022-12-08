#include <bits/stdc++.h>
using namespace std;
char s[100005];

main() {
	int t, n, i, j, k, cnt, flag;
	scanf("%d", &t);
	getchar();
	while (t--) {
		memset(s, 0, sizeof(s));
		gets(s);
		n = strlen(s);
		i = cnt = 0;
		while (i < n - 1) {
			if (s[i] == ' ') {
				++i;
				continue;
			}
			if (s[i] == s[i + 1]) {
				s[i + 1] = ' ';
				++cnt;
			}
			if (s[i] == s[i + 2]) {
				s[i + 2] = ' ';
				++cnt;
			}
			++i;
		}
		printf("%d\n", cnt);
	}
}