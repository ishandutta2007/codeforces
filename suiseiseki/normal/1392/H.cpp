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
const int Maxn=2000001;
const int Mod=998244353;
int n,m;
int inv[Maxn+5];
void init(){
	inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	int ans=1ll*(n+m+1)*inv[m+1]%Mod;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=(sum+inv[i])%Mod;
	}
	sum=(1ll*sum*m+1)%Mod;
	ans=1ll*ans*sum%Mod;
	printf("%d\n",ans);
	return 0;
}