#include <cstdio>

int main(){
	int n, t;
	scanf("%d%d", &n, &t);
	if (n == 1){
		printf("%d\n", t < 10 ? t : -1);
	}
	else{
		printf("%d", t < 10 ? t : 1);
		for (int i = 1; i < n; ++i)
			putchar('0');
		puts("");
	}
	return 0;
}