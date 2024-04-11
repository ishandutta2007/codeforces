#include <cstdio>

int main(){
	int n;
	char s[10];
	scanf("%d%*s%s", &n, &s);
	if (s[0] == 'w')
		printf("%d\n", 366 / 7 + (n == 5 || n == 6));
	else
		printf("%d\n", n <= 29 ? 12 : n == 30 ? 11 : 7);
	return 0;
}