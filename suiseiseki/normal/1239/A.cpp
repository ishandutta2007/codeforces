#include <cstdio>
#define M 1000000007
long long F[110000]={0,1};
int main(){
	for(int i=2;i<110000;i++)F[i]=(F[i-1]+F[i-2])%M;
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld\n",2*(F[n+1]+F[m+1]-1)%M);
	return 0;
}