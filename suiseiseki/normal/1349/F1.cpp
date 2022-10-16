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
const int Maxn=10000;
const int Mod=998244353;
int n;
int frac[Maxn+5],inv_f[Maxn+5];
int inv[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn]=quick_power(frac[Maxn],Mod-2,Mod);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	for(int i=1;i<=Maxn;i++){
		inv[i]=1ll*inv_f[i]*frac[i-1]%Mod;
	}
}
int f[Maxn+5];
int ans[Maxn+5];
int main(){
	init();
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(i!=1){
			int now=(i>>1);
			for(int j=now;j>=0;j--){
				f[j]=(1ll*(j+1)*f[j]+1ll*(i-j)*f[j-1])%Mod;
			}
			if(!(i&1)){
				f[now]=f[now-1];
			}
		}
		for(int j=(i>>1)-1;j>=0;j--){
			int tmp=1ll*f[j]*inv_f[i]%Mod;
			ans[j]=(ans[j]+tmp)%Mod;
			ans[i-j-1]=(ans[i-j-1]+tmp)%Mod;
		}
		if(i&1){
			ans[i>>1]=(ans[i>>1]+1ll*f[i>>1]*inv_f[i])%Mod;
		}
	}
	for(int i=0;i<n;i++){
		int tmp=1ll*ans[i]*frac[n]%Mod;
		printf("%d ",tmp);
	}
	puts("");
	return 0;
}