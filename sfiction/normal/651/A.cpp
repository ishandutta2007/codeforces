#include <cstdio>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b == 2 ? 0 : a + b - 2 - !((a - b) % 3));
	return 0;
}