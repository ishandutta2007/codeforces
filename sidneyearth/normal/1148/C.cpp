#include <stdio.h>
const int maxn = 2000100;
int a[maxn], X[maxn], Y[maxn], c;
void Do(int x, int y){
	a[x] ^= a[y] ^= a[x] ^= a[y];
	++c;
	X[c] = x;
	Y[c] = y;
}
void Swap(int x, int y, int n){
	if(x > y) x ^= y ^= x ^= y;
	if(y - x >= n / 2)
		Do(x, y);
	else if(x <= n / 2 && y <= n / 2){
		Do(x, n);
		Do(y, n);
		Do(x, n);
	}
	else if(x <= n / 2 && y > n / 2){
		Do(x, n);
		Do(1, y);
		Do(1, n);
		Do(x, n);
		Do(1, y);
	}
	else if(x > n / 2 && y > n / 2){
		Do(1, x);
		Do(1, y);
		Do(1, x);
	}
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		while(a[i] != i) Swap(i, a[i], n);
	printf("%d\n", c);
	for(int i = 1; i <= c; ++i)
		printf("%d %d\n", X[i], Y[i]);
	return 0;
}