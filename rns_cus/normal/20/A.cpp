#include <bits/stdc++.h>
using namespace std;

char s[111];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	while (len > 1 && s[len-1] == '/') len --;
	for (int i = 0; i < len; i ++) {
		if (i && s[i] == '/' && s[i-1] == '/') continue;
		printf("%c", s[i]);
	}
	puts("");
	return 0;
}