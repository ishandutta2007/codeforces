#include <cstdio>

const int MAXN = 5E5 + 10;

int n;
int a[MAXN << 1];

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		int t = i + 1 >> 1;
		if (i & 1)
			a[t] = a[n - t + 1] = i;
		else//n - i
			a[n + t] = a[n * 2 - t] = i;
	}
	a[2 * n] = n;
	if (n & 1)
		a[n + 1 >> 1] = n;
	else
		a[n + (n >> 1)] = n;
	for (int i = 2 * n; i > 0; --i)
		printf("%d%c", a[i], "\n "[i > 1]);
	return 0;
}