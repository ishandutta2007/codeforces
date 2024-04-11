#include <bits/stdc++.h>
using namespace std;

char s[1001001];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) {
		if (s[i] == '0') {
			for (int j = 0; j < len; j ++) if (j != i) printf("%c", s[j]);
			puts("");
			return 0;
		}
	}
	for (int i = 0; i < len - 1; i ++) printf("%c", s[i]);
	puts("");
	return 0;
}