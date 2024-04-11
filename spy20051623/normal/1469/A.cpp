#include <bits/stdc++.h>
using namespace std;

main() {
	char s[120];
	int t, cnt, v, i, flag;
	scanf("%d\n", &t);
	while (t--) {
		gets(s);
		cnt = v = 0;
		flag = 1;
		for (i = 0; i < strlen(s); ++i) {
			if (s[i] == '(')
				++v;
			else if (s[i] == ')')
				--v;
			else if (s[i] == '?')
				++cnt;
			if (v < 0) {
				--cnt;
				++v;
			}
			if (cnt < 0) {
				flag = 0;
				break;
			}
		}
		if ((cnt + v) % 2)
			flag = 0;
		cnt = v = 0;
		if (flag)
			for (i = strlen(s) - 1; i >= 0; --i) {
				if (s[i] == ')')
					++v;
				else if (s[i] == '(')
					--v;
				else if (s[i] == '?')
					++cnt;
				if (v < 0) {
					--cnt;
					++v;
				}
				if (cnt < 0) {
					flag = 0;
					break;
				}
			}
		if ((cnt + v) % 2)
			flag = 0;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}