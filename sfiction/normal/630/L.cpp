#include <cstdio>

int main(){
	char s[6];
	scanf("%s", s);
	long long a = 0, b = 1;
	a = a * 10 + s[0] - '0';
	a = a * 10 + s[2] - '0';
	a = a * 10 + s[4] - '0';
	a = a * 10 + s[3] - '0';
	a = a * 10 + s[1] - '0';
	b = b * a % 100000;
	b = b * a % 100000;
	b = b * a % 100000;
	b = b * a % 100000;
	b = b * a % 100000;
	printf("%05d\n", b);
	return 0;
}