#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int n,f[1<<17],a[1<<17],b[1<<17],c[1<<17][18],s[1<<17],d[18],e[1<<17],A[1<<17],B[1<<17],C[1<<17];
int main(){
	scanf("%d",&n);
	f[0]=0,f[1]=1;
	for(int i=2;i<1<<17;i++)f[i]=(f[i-1]+f[i-2])%M;
	s[0]=0;
	for(int i=1;i<1<<17;i++)s[i]=s[i>>1]+i%2;
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a[x]++;
	}
	for(int i=0;i<1<<17;i++)b[i]=c[i][s[i]]=a[i];
	for(int i=0;i<17;i++)for(int j=0;j<1<<17;j++)if(j>>i&1){
		int o=a[j],p=a[j^1<<i];
		a[j]=(p-o+M)%M;a[j^1<<i]=(o+p)%M;
		for(int k=0;k<=s[j];k++)c[j][k]=(c[j][k]+c[j^1<<i][k])%M;
	}
	for(int i=0;i<1<<17;i++){
		a[i]=1ll*a[i]*a[i]%M;
		for(int j=0;j<=17;j++){
			d[j]=0;
			for(int k=0;k<=j;k++)d[j]=(d[j]+1ll*c[i][k]*c[i][j-k])%M;
		}
		for(int k=0;k<=17;k++)c[i][k]=d[k];
	}
	int rev=(M+1)/2;
	for(int i=0;i<17;i++)for(int j=0;j<1<<17;j++)if(j>>i&1){
		int o=a[j],p=a[j^1<<i];
		a[j]=(p-o+M)%M;a[j^1<<i]=(o+p)%M;
		a[j]=1ll*a[j]*rev%M;a[j^1<<i]=1ll*a[j^1<<i]*rev%M;
		for(int k=0;k<=17;k++)c[j][k]=(c[j][k]-c[j^1<<i][k]+M)%M;
	}
	memcpy(A,a,sizeof(a));
	memcpy(B,b,sizeof(a));
	for(int i=0;i<1<<17;i++)C[i]=c[i][s[i]];
	for(int i=0;i<1<<17;i++)a[(1<<17)-1-i]=1ll*f[i]*A[i]%M,e[(1<<17)-1-i]=1ll*f[i]*C[i]%M,b[(1<<17)-1-i]=1ll*f[i]*B[i]%M;
	for(int i=0;i<17;i++)for(int j=0;j<1<<17;j++)if(j>>i&1){
		a[j]=(a[j]+a[j^1<<i])%M;
		e[j]=(e[j]+e[j^1<<i])%M;
		b[j]=(b[j]+b[j^1<<i])%M;
	}
	for(int i=0;i<1<<17;i++)a[i]=1ll*a[i]*b[i]%M*e[i]%M;
	for(int i=0;i<17;i++)for(int j=0;j<1<<17;j++)if(j>>i&1){
		a[j]=(a[j]-a[j^1<<i]+M)%M;
	}
	long long ans=0;
	for(int i=0;i<17;i++)ans=(ans+a[(1<<17)-1-(1<<i)])%M;
	printf("%I64d\n",ans);
	return 0;
}