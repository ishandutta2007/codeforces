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
const int Maxn=2500;
const int Maxm=100000;
const int Mod=1000000007;
int n;
int a[Maxn+5];
int sum;
int f[Maxm+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	f[1]=1ll*(sum-1)*(sum-1)%Mod*quick_power(sum,Mod-2,Mod)%Mod;
	f[2]=((f[1]<<1)%Mod-1+Mod)%Mod;
	for(int i=3;i<=Maxm;i++){
		f[i]=(f[i-1]<<1)%Mod;
		f[i]=(f[i]-f[i-2]+Mod)%Mod;
		f[i]=(f[i]-1ll*(sum-1)*quick_power(sum-(i-1),Mod-2,Mod)%Mod+Mod)%Mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+f[a[i]])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}