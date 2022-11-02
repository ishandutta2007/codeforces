#include <bits/stdc++.h>
using namespace std;

#define N 200200

char s[N], a[N], b[N], t[N];

void print(char *s) {
	if (strlen(s) == 0) {
		puts("-"); return;
	}
	putchar('"');
	printf("%s", s + 1);
	putchar('"');
	puts("");
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s), runs = 0, num = 1;
	for (int i = 0; i <= len; i ++) {
		if (s[i] == ',' || s[i] == ';' || i == len) {
			t[runs] = 0;
			if (!runs || runs >= 2 && t[0] == '0') num = 0;
			if (num) strcat(a, ","), strcat(a, t);
			else strcat(b, ","), strcat(b, t);
			num = 1, runs = 0;
		}
		else {
			if (s[i] < '0' || s[i] > '9') num = 0;
			t[runs++] = s[i];
		}
	}
	print(a);
	print(b);
	return 0;
}