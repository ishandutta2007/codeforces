#include <cstdio>
const int Maxn=200000;
const int Mod=998244353;
int quick_power(int a,int b){
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
int n,m;
int f[Maxn+5];
int frac[Maxn+5],inv_f[Maxn+5],power_2[Maxn+5],inv_2;
void init(){
	frac[0]=inv_f[0]=power_2[0]=1;
	inv_2=quick_power(2,Mod-2);
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
		power_2[i]=(power_2[i-1]<<1)%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2);
	for(int i=Maxn-1;i>0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	int ans=0;
	int tmp;
	for(int i=n-1;i<=m;i++){
		tmp=C(i-1,n-2);
		tmp=1ll*tmp*power_2[n-2]%Mod;
		tmp=1ll*tmp*(n-2)%Mod;
		tmp=1ll*tmp*inv_2%Mod;
		ans=(ans+tmp)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}