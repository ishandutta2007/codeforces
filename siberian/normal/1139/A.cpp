#include <stdio.h>

int main()
{
	int result = 0;
	int n;
	char s[65001];
	
	scanf("%d", &n);
	
	scanf("%s", s);

	for (int i = 0; i < n; i++)
		if ((int)(s[i] - '0') % 2 == 0)
			result += i + 1;

	printf("%d\n", result);
}