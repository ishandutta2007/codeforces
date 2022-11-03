#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", n & 1 ? 0 : n & 2 ? n / 4 : n / 4 - 1);
	return 0;
}