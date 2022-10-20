#include <cstdio>

int main(){
//	freopen("cf1080a.in", "r", stdin);
//	freopen("cf1080a.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n", (n*2-1)/k+1 + (n*5-1)/k+1 + (n*8-1)/k+1);
	return 0;
}