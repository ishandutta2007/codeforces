#include <bits/stdc++.h>
using namespace std;

char s[1001001];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	int x = 0, y = 0;
	for (int i = 0; i < len; i ++) {
		if (s[i] == 'x') x ++;
		else y ++;
	}
	if (x > y) {
		for (int i = 0; i < x - y; i ++) printf("%c", 'x');
	}
	else {
		for (int i = 0; i < y - x; i ++) printf("%c", 'y');
	}
	puts("");
	return 0;
}