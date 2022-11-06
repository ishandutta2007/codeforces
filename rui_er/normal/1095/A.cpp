#include <stdio.h>

int main()
{
	int n;
	char s[101];
	scanf("%d%s", &n, s);
	int k = 1;
	for(int i=0;i<n;i+=k,k++) printf("%c", s[i]);
	printf("\n");
	return 0;
}