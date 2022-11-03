#include <cstdio>

int n, d, h;

int getnum(int x){
	return x == 1 ? h + 1 : x == h + 1 ? 1 : x;
}

int main(){
	scanf("%d%d%d", &n, &d, &h);
	if (d == 1)
		puts(n == 2 && h == 1 ? "1 2" : "-1");
	else if (d > 2 * h)
		puts("-1");
	else{
		for (int i = 1; i <= d; ++i)
			printf("%d %d\n", getnum(i), getnum(i + 1));
		for (int i = d + 2; i <= n; ++i)
			printf("%d %d\n", getnum(2), i);
	}
	return 0;
}