#include <cstdio>
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
const int Maxn=200000;
const int Mod=1000000007;
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
int C(int n,int m){
	if(m<0||n<m){
		return 0;
	}
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
void solve(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	int x=std::min(1-l,r-n);
	int ans=1ll*x*C(n,n>>1)%Mod;
	if(n&1){
		ans=(ans+1ll*x*C(n,(n+1)>>1))%Mod;
	}
	int pos_l=1,pos_r=n;
	for(int i=1;i<=n;i++){
		x++;
		while(x+pos_r>r){
			pos_r--;
		}
		while(pos_l-x<l){
			pos_l++;
		}
		int down=n-pos_r,up=pos_l-1;
		ans=(ans+C(n-down-up,(n>>1)-up))%Mod;
		if(n&1){
			ans=(ans+C(n-down-up,((n+1)>>1)-up))%Mod;
		}
	}
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