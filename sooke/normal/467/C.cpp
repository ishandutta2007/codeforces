#include <cstdio>
#define Max(x , y) ((x) > (y) ? (x) : (y))

int n , m , c;
long long a[5001] , f[5001][5001];

int main(){
	scanf("%d%d%d" , &n , &m , &c);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &a[i]);
	for(int i = 2 ; i <= n ; i++)
		a[i] += a[i - 1];
	for(int i = 1 ; i <= c ; i++)
		for(int j = i * m ; j <= n ; j++)
			f[i][j] = Max(f[i][j - 1] , f[i - 1][j - m] + a[j] - a[j - m]);
	printf("%lld\n" , f[c][n]);
	return 0;
}