#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, r, c, d;
	char s[200];
	int a[20];
	scanf("%d", &t);
	getchar();
	while (t--) {
		gets(s);
		if (sscanf(s, "R%dC%d", &r, &c) == 2) {
			memset(a, 0, sizeof(a));
			--c;
			if (c == 0) {
				d = 1;
			} else {
				d = 0;
				while (c >= 0) {
					a[d] = c % 26;
					c /= 26;
					--c;
					++d;
				}
			}
			while (d) {
				printf("%c", a[d - 1] + 'A');
				--d;
			}
			printf("%d\n", r);
		} else {
			r = c = 0;
			for (int i = 0; i < strlen(s); ++i) {
				if (s[i] >= 'A') {
					c *= 26;
					c += s[i] - 'A' + 1;
				} else {
					r *= 10;
					r += s[i] - '0';
				}
			}
			printf("R%dC%d\n", r, c);
		}
	}
	return 0;
}