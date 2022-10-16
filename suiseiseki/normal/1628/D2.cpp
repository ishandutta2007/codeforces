#include<bits/stdc++.h>
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
const int inv_2=(Mod+1)/2;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
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
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int sum=0;
	for(int i=0;i<m;i++){
		sum=(sum+1ll*inv_f[i]*inv_f[n-i]%Mod*(m-i))%Mod;
	}
	int ans=1ll*quick_power(inv_2,n-1,Mod)*k%Mod*sum%Mod*fac[n]%Mod;
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