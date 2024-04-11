#include <bits/stdc++.h>
using namespace std;

char key[] = "qwertyuiopasdfghjkl;zxcvbnm,./";

int x;
char t[1010], s[1010];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", t);
	if (t[0] == 'R') x = -1;
	else x = 1;
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) {
		for (int j = 0; ;j ++) {
			if (key[j] == s[i]) {
				printf("%c", key[j+x]); break;
			}
		}
	}
	puts("");
	return 0;
}