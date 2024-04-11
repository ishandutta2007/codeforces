#include<stdio.h>
typedef long long LL;
const double pi = 3.14159265358979;
#define N 100010
int x[N], y[N], r[N], dep[N], n;
LL dist(int x, int y){ return 1ll * x * x + 1ll * y * y; }
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d %d %d", x + i, y + i, r + i);
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)if(r[j] > r[i]) {
			if( dist( x[i] - x[j], y[i] - y[j]) <= 1ll * r[j] * r[j] ){
				dep[i] ++;
			}
		}

	LL ans = 0;
	for(int i = 1; i <= n; i ++){
		if(dep[i] == 0) ans += 1ll * r[i] * r[i];
		else if(dep[i] & 1) ans += 1ll * r[i] * r[i];
		else ans -= 1ll * r[i] * r[i];
	}
	printf("%.10lf\n", pi * ans);
}