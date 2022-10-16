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
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,k;
int fac[Maxn<<1|5],inv_f[Maxn<<1|5];
void init(){
	fac[0]=1;
	for(int i=1;i<=(Maxn<<1);i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn<<1]=find_inv(fac[Maxn<<1]);
	for(int i=(Maxn<<1)-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	if(m<0||n<m){
		return 0;
	}
	return 1ll*fac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int p[Maxn+5],q[Maxn+5];
int main(){
	init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		q[p[i]]=i;
	}
	k--;
	for(int i=1;i<n;i++){
		if(q[p[i]+1]>q[p[i+1]+1]){
			k--;
		}
	}
	printf("%d\n",C(k+n,k));
	return 0;
}