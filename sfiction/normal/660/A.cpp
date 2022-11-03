#include <cstdio>

const int MAXN = 2E3 + 10;

int a[MAXN];

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 1; i < n; ++i)
		cnt += gcd(a[i - 1], a[i]) > 1;
	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i){
		if (i && gcd(a[i - 1], a[i]) > 1)
			printf("1 ");
		printf("%d%c", a[i], "\n "[i < n - 1]);
	}
	return 0;
}