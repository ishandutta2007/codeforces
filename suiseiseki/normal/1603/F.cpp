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
const int Maxn=10000000;
const int Mod=998244353;
const int inv_2=(Mod+1)/2;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int pow_2[Maxn+5],fac[Maxn+5],inv_f[Maxn+5];
int n,k,x;
void solve(){
	scanf("%d%d%d",&n,&k,&x);
	if(x==0){
		if(n>k){
			puts("0");
			return;
		}
		int ans=1ll*fac[k]*inv_f[k-n]%Mod;
		for(int i=0;i<n;i++){
			ans=1ll*ans*pow_2[i]%Mod;
		}
		printf("%d\n",ans);
	}
	else{
		int ans=0;
		int coef=1;
		int all_val=quick_power(2,n,Mod);
		for(int i=0;i<=k;i++,all_val=1ll*all_val*inv_2%Mod){
			int val=(i==0?1:(1+1ll*inv_f[k]*fac[k-1]%Mod*(Mod-pow_2[i]+1)))%Mod;
			ans=(ans+1ll*coef*inv_f[i]%Mod*val)%Mod;
			coef=1ll*coef*(all_val-1)%Mod*(pow_2[k-i]-1)%Mod;
			coef=1ll*coef*pow_2[i]%Mod;
		}
		printf("%d\n",ans);
	}
}
int main(){
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*(pow_2[i]-1)%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(pow_2[i+1]-1)%Mod;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}