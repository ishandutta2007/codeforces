#include <stdio.h>

int main() {
	int a, b, c;
	char s[2][5] = {"NO", "YES"};
	scanf("%d %d %d", &a, &b, &c);
	int tag = 0;
	if ((c - a) % b == 0 || (c - a) % b == 1) tag = 1;
	if (c == a + 1 || c < a) tag = 0;
	puts(s[tag]);
	return 0;
}