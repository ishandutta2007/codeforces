#include<cstdio>
using namespace std;
const int o=210;
int n,f[o][o][40],vis[o][o][40],fac[o],inv[o],MOD,a1,ans;
int calc(int i,int sum,int k){
	if(i==n) return fac[n];
	if(!k) return fac[n]*1ll*inv[n-i]%MOD;
	if(vis[i][sum][k]==a1) return f[i][sum][k];
	vis[i][sum][k]=a1;f[i][sum][k]=0;
	for(int cnt=(a1-sum)/k;cnt>=0;--cnt) if(k<2||i+cnt>n-a1+1-k)	
		f[i][sum][k]=(f[i][sum][k]+inv[cnt]*1ll*calc(i+cnt,sum+cnt*k,k-1))%MOD;
	return f[i][sum][k];
}
int main(){
	scanf("%d%d",&n,&MOD);inv[1]=1;
	for(int i=2;i<=n;++i) inv[i]=MOD-MOD/i*1ll*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%MOD,inv[i]=inv[i-1]*1ll*inv[i]%MOD;
	for(;(a1+1)*(a1+1)<=n;++a1);
	if((a1=n-2*a1-1)<1) a1=1;
	for(;a1<=n;++a1) ans=(ans+calc(0,0,n+1-a1))%MOD;
	printf("%d",ans);
	return 0;
}