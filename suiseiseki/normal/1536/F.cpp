#include <cstdio>
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
const int Maxn=1000000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n;
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
	if(n<m||m<0){
		return 0;
	}
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d",&n);
	int ans=0;
	for(int i=(n&1);i<=n;i+=2){
		ans=(ans+1ll*C(n-i,i)*fac[n-i-1])%Mod;
	}
	ans=2ll*ans*n%Mod;
	printf("%d\n",ans);
	return 0;
}