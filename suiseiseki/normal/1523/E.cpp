#include <cstdio>
#include <cstring>
#include <algorithm>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=100000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,k;
int sum[Maxn+5];
int fac[Maxn+5],inv_f[Maxn+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	if(m<0||n<m){
		return 0;
	}
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
void solve(){
	scanf("%d%d",&n,&k);
	int ans=0;
	for(int i=1;i<=n&&n-1ll*(i-1)*(k-1)>=i;i++){
		int sum=C(n-(i-1)*(k-1),i);
		ans=(ans+1ll*sum*fac[n-i]%Mod*fac[i])%Mod;
	}
	ans=1ll*ans*inv_f[n]%Mod;
	ans=(ans+1)%Mod;
	printf("%d\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}