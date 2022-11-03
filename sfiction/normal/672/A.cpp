#include <cstdio>

char s[5000];

int main(){
	char *p = s;
	for (int i = 1; p - s < 1000; ++i)
		p += sprintf(p, "%d", i);
	int n;
	scanf("%d", &n);
	printf("%c\n", s[n - 1]);
	return 0;
}