#include <cstdio>
#define Maxn 40

int n , m;
long long f[Maxn][Maxn];

int main(){
	scanf("%d%d" , &n , &m);
	f[1][0] = f[1][1] = 1;
	for(int i = 2 ; i <= n ; i++){
		f[i][0] = 1;
		for(int j = 1 ; j <= n ; j++)
			for(int k = 0 ; k < j ; k++)
				f[i][j] += f[i - 1][k] * f[i - 1][j - k - 1];
	}
	printf("%lld\n" , f[n][n] - f[m - 1][n]);
	return 0;
}