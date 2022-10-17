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
const int Maxn=200000;
const int Mod=998244353;
int f[Maxn+5];
int sum[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	f[0]=sum[0]=1;
	int pow_2=1;
	for(int i=1;i<=n;i++){
		f[i]=sum[i-1];
		sum[i]=(sum[i-2]+f[i])%Mod;
		pow_2=(pow_2<<1)%Mod;
	}
	int ans=1ll*f[n]*quick_power(pow_2,Mod-2,Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}