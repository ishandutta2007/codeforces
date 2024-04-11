#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", __builtin_popcount(n));
	return 0;
}