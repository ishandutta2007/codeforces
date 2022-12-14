#include <stdio.h>

int main() {
	int tag = 1;
	char c[10];
	scanf("%s\n%s\n%s", c, c + 3, c + 6);
	for (int i = 0; i < 4; i ++) if (c[i] != c[8-i]) tag = 0;
	if (tag) puts("YES");
	else puts("NO");
	return 0;
}