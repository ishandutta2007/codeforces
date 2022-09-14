
#include <bits/stdc++.h>

using namespace std;

char s[100001];

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d%s", &n, &s);
	int l = 0, r = n * 2, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		int fa = -1, fd, rb = -1, f = 1;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'P') {
				fd = fa == -1 ? 0 : i - fa;
				if (fd > m) {
					f = 0;
					break;
				}
				rb = i + max((m - fd) / 2, m - 2 * fd);
				fa = -1;
			}
			else if (s[i] == '*' && fa == -1 && i > rb)
				fa = i;
		}
		if (fa > -1)
			f = 0;
		if (f)
			r = m;
		else
			l = m;
	}
	printf("%d\n", r);
}