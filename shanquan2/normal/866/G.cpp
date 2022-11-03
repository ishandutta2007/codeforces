#include<bits/stdc++.h>
using namespace std;

const int M=1000000007,N=255;
int n,m,p[15],c[105],f[N],a[N],b[N],d[N],x[N],y[N],z[N<<1];
long long T;
void mul(){
	memset(z,0,sizeof(z));
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)z[i+j]=(z[i+j]+1ll*x[i]*y[j])%M;
	for(int i=N*2-1;i>=N;i--)if(z[i]){
		int t=z[i];z[i]=0;
		for(int j=0;j<m;j++)z[i-c[j]]=(z[i-c[j]]+t)%M;
	}
}
void Mul(int u[],int v[]){
	memcpy(x,u,sizeof(x));memcpy(y,v,sizeof(y));
	mul();
	memcpy(u,z,N<<2);
}
void fexp(long long t){
	if(t==1){
		memcpy(d,b,sizeof(d));
		return;
	}
	fexp(t>>1);
	Mul(d,d);
	if(t&1)Mul(d,b);
}
int main(){
	scanf("%d%d%I64d",&n,&m,&T);
	for(int i=0;i<n;i++)scanf("%d",&p[i]);
	for(int i=0;i<m;i++)scanf("%d",&c[i]);
	f[0]=1;
	for(int i=1;i<N;i++)for(int j=0;j<m;j++)if(c[j]<=i)f[i]=(f[i]+f[i-c[j]])%M;
//	for(int i=0;i<20;i++)printf("%d ",f[i]);printf("\n");
	for(int i=0;i<n;i++){
		memset(b,0,sizeof(b));b[1]=1;
		fexp(p[i]);
//		for(int i=0;i<20;i++)printf("%d ",d[i]);printf("\n\n");
		for(int i=0;i<N;i++)a[i]=(a[i]+d[i])%M;
	}
	memcpy(b,a,sizeof(b));
	fexp(T);
	long long ans=0;
	for(int i=0;i<N;i++)ans=(ans+1ll*f[i]*d[i])%M;
	printf("%I64d\n",ans);
	return 0;
}