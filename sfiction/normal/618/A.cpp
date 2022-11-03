#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool flag = false;
	for (; n; ){
		int t = 31 - __builtin_clz(n);
		if (flag)
			putchar(' ');
		printf("%d", t + 1);
		flag = true;
		n -= 1 << t;
	}
	return 0;
}