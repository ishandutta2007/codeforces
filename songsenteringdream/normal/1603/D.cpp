#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10;const long long inf=1e18;
int T,n=o-10,k;long long f[o][20],phi[o];
inline long long c(int l,int r){
	long long res=0;
	for(long long j;l<=r;l=j+1) j=r/(r/l),res+=phi[r/l]*(j-l+1);
	return res;
}
void slv(int k,int l,int r,int tl,int tr){
	if(l>r) return;
	int md=l+r>>1,tmd;long long cost=c(min(tr,md-1)+1,md);
	f[md][k]=inf;
	for(int i=min(tr,md-1);i>=tl;cost+=phi[md/(i--)])
		if(cost+f[i][k-1]<f[md][k]) f[md][k]=cost+f[i][k-1],tmd=i;
	slv(k,l,md-1,tl,tmd);slv(k,md+1,r,tmd,tr);
}
int main(){
	for(int i=1,j;i<=n;++i) for(phi[i]+=i,j=i*2;j<=n;j+=i) phi[j]-=phi[i];
	for(int i=1;i<=n;++i) phi[i]+=phi[i-1],f[i][1]=i*(i+1ll)/2;
	for(int i=2;i<20;++i) slv(i,i,n,i-1,n);
	for(scanf("%d",&T);T--;printf("%lld\n",(k>25||(1<<k)>n)?n:f[n][k])) scanf("%d%d",&n,&k);
	return 0;
}