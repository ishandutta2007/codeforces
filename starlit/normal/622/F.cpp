#include<cstdio>
#define N 1000006
#define M 1000000007
int n,k,t;
long long x,y,f=1,fac[N],inv[N],ans,sum;
int main(){
	scanf("%d%d",&n,&k);k++;
	inv[0]=inv[1]=1,fac[0]=n-k;
	for(int i=2;i<=k;i++)
	inv[i]=-M/i*inv[M%i]%M;
	for(int i=1;i<=k;i++)
	fac[i]=fac[i-1]*(n-k+i)%M,
	inv[i]=inv[i]*inv[i-1]%M;
	for(int i=0;i<=k;i++){
		for(x=i,t=k-1,y=!!i;t;t>>=1)
		t&1?y=y*x%M:0,x=x*x%M;
		(sum+=y)%=M;
		ans+=sum*f%M*(i==k?1:fac[k-i-1])%M*inv[i]%M*inv[k-i]%M*(k-i&1?-1:1);
		f=f*(n-i)%M;
	}
	printf("%d",(ans%M+M)%M);
}