#include <cstdio>
#include <cstring>
#define Maxn 100000
double f[2][1005];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=n;i>0;i--){
		memset(f[i&1],0,sizeof f[i&1]);
		for(int j=1;j<=mn(1000,i+1);j++){
			f[i&1][j]+=f[(i&1)^1][j]*1.0*(k-1)/k;
			f[i&1][j]+=(f[(i&1)^1][j+1]+j)*1.0/k*1.0/(j+1);
			f[i&1][j]+=(f[(i&1)^1][j]*j*1.0+j*(j+1.0)/2.0)/k*1.0/(j+1);
		}
	}
	printf("%.10lf\n",f[1][1]*k);
	return 0;
}