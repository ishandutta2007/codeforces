#include <stdio.h>
int t, n;
main()
{
	scanf("%d\n", &n);
	while (n--) {
		char s[9];
		gets(s);
		t += "4!8D6<"[*s%7]-48;
	}
	printf("%d\n", t);
}