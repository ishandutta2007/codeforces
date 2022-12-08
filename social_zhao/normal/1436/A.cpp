#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1, u; i <= n; i++) scanf("%d", &u), k -= u;
		printf(k == 0? "YES\n" : "NO\n");
	} 
	return 0;
}