#include <cstdio>

int main(){
	char s[3];
	scanf("%s", s);
	int a = (s[0] == 'a' || s[0] == 'h') + (s[1] == '1' || s[1] == '8');
	printf("%d\n", a == 2 ? 3 : a == 1 ? 5 : 8);
	return 0;
}