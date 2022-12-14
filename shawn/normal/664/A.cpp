#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

struct String {
	int l;
	char s[200];
} a, b;

int main() {
	scanf("%s%s", a.s + 1, b.s + 1);
	a.l = strlen(a.s + 1);
	b.l = strlen(b.s + 1);
	if (a.l != b.l) return puts("1"), 0;
	else {
		if (strcmp(a.s + 1,  b.s + 1) == 0) return printf("%s", a.s + 1), 0;
		else return puts("1"), 0;
	}
	return 0;
}