#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	int n = 1 << k;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			putchar(__builtin_parity(i & j) ? '*' : '+');
		puts("");
	}
	return 0;
}