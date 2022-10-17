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
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=1500;
const int Maxk=100000;
const int Mod=1000000007;
int n,m;
int p;
int k;
int frac[Maxk+5],inv_f[Maxk+5];
int g[Maxn+5],q[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxk;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxk]=quick_power(frac[Maxk],Mod-2,Mod);
	for(int i=Maxk-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
int f[Maxn+5][Maxn+5],s[Maxn+5][Maxn+5],h[Maxn+5][Maxn+5];
int main(){
	init();
	scanf("%d%d",&n,&m);
	scanf("%d%d",&p,&k);
	p=1ll*p*quick_power(k,Mod-2,Mod)%Mod;
	scanf("%d",&k);
	for(int i=0;i<=min(m,k);i++){
		g[i]=1ll*C(k,i)*quick_power(p,i,Mod)%Mod*quick_power((1-p+Mod)%Mod,k-i,Mod)%Mod;
	}
	for(int i=1;i<=m;i++){
		q[i]=(q[i-1]+g[i-1])%Mod;
	}
	f[0][m]=s[0][m]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1ll*g[m-j]*((1ll*(s[i-1][m]-s[i-1][m-j]+Mod)%Mod)*q[j]%Mod-h[i-1][j]+Mod)%Mod;
			s[i][j]=(s[i][j-1]+f[i][j])%Mod;
			h[i][j]=(h[i][j-1]+1ll*g[j-1]*s[i][j-1])%Mod;
		}
	}
	printf("%d\n",s[n][m]);
	return 0;
}