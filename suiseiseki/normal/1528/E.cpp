#include <cstdio>
const int Maxn=1000000;
const int Mod=998244353;
const int inv_2=(Mod+1)>>1;
const int inv_3=(Mod+1)/3;
const int inv_6=(Mod+1)/6;
int n;
int f[Maxn+5],sum_f[Maxn+5];
int g[Maxn+5],sum_g[Maxn+5];
int main(){
	scanf("%d",&n);
	f[0]=1,f[1]=1;
	sum_f[0]=1,sum_f[1]=2;
	for(int i=2;i<=n;i++){
		g[i]=f[i]=1ll*f[i-1]*(f[i-1]+1)%Mod*inv_2%Mod;
		f[i]=(f[i]+1ll*f[i-1]*sum_f[i-2])%Mod;
		g[i]=(g[i]+1ll*f[i-1]*(sum_f[i-2]-1+Mod))%Mod;
		sum_f[i]=(sum_f[i-1]+f[i])%Mod;
	}
	int ans=1ll*f[n]*(f[n]+1)%Mod*(f[n]+2)%Mod*inv_6%Mod;
	ans=(ans+1ll*f[n]*(f[n]+1)%Mod*inv_2%Mod*sum_f[n-1])%Mod;
	int sum=sum_f[n-1];
	int sum_1=0,sum_2=0;
	for(int i=0;i<n;i++){
		sum_1=(sum_1+1ll*f[i]*(f[i]+1)%Mod*inv_2)%Mod;
		sum_2=(sum_2+1ll*(sum-f[i]+Mod)*f[i])%Mod;
		sum=(sum-f[i]+Mod)%Mod;
	}
	ans=(ans+1ll*(sum_1+sum_2)*f[n])%Mod;
	ans=(0ll+(ans<<1)-1+Mod)%Mod;
	for(int i=2;i<=n;i++){
		sum_g[i]=(sum_g[i-1]+g[i])%Mod;
	}
	for(int i=2;i<=n;i++){
		ans=(ans+1ll*g[i]*sum_g[n-i+1])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}