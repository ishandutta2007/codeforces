#include <cstdio>
#include <algorithm>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b>0){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Mod=998244353;
const int G=3;
const int Maxk=400000;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,k;
namespace Poly{
	int inv[Maxk+5],pow_G[Maxk+5];
	void init_G(int len){
		int t=quick_power(G,(Mod-1)/len,Mod);
		pow_G[len>>1]=1;
		for(int i=(len>>1)+1;i<len;i++){
			pow_G[i]=1ll*pow_G[i-1]*t%Mod;
		}
		for(int i=(len>>1)-1;i>0;i--){
			pow_G[i]=pow_G[i<<1];
		}
	}
	void init(){
		int len=1;
		while(len<=Maxk){
			len<<=1;
		}
		len>>=1;
		init_G(len);
	}
	void NTT(int *a,int flag,int n){
		static int R[Maxk+5],last_len=0;
		int len=1,L=0;
		while(len<n){
			len<<=1;
			L++;
		}
		if(last_len!=len){
			for(int i=0;i<len;i++){
				R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
			}
		}
		for(int i=0;i<len;i++){
			if(i<R[i]){
				std::swap(a[i],a[R[i]]);
			}
		}
		for(int j=1;j<len;j<<=1){
			int *t=pow_G+j;
			for(int k=0;k<len;k+=(j<<1)){
				for(int l=0;l<j;l++){
					int Nx=a[k+l],Ny=1ll*t[l]*a[j+k+l]%Mod;
					a[k+l]=(Nx+Ny)%Mod;
					a[j+k+l]=(Nx-Ny+Mod)%Mod;
				}
			}
		}
		if(flag==-1){
			std::reverse(a+1,a+len);
			for(int i=0,t=find_inv(len);i<len;i++){
				a[i]=1ll*a[i]*t%Mod;
			}
		}
	}
}
using Poly::NTT;
int fac[Maxk+5],inv_f[Maxk+5],C[Maxk+5],inv[Maxk+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxk;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxk]=find_inv(fac[Maxk]);
	for(int i=Maxk-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	inv[1]=1;
	for(int i=2;i<=Maxk;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	C[0]=1;
	for(int i=1;i<=k;i++){
		C[i]=1ll*C[i-1]*(n-i+1+Mod)%Mod*inv[i]%Mod;
	}
}
int f[Maxk+5],g[Maxk+5];
int main(){
	Poly::init();
	scanf("%d%d",&n,&k);
	init();
	for(int i=0;i<=k;i++){
		if(i&1){
			f[i]=(Mod-inv_f[i])%Mod;
		}
		else{
			f[i]=inv_f[i];
		}
		g[i]=1ll*quick_power(i,k,Mod)*inv_f[i]%Mod;
	}
	int len=1;
	while(len<=(k<<1)){
		len<<=1;
	}
	NTT(f,1,len);
	NTT(g,1,len);
	for(int i=0;i<len;i++){
		f[i]=1ll*f[i]*g[i]%Mod;
	}
	NTT(f,-1,len);
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=(ans+1ll*C[i]*f[i]%Mod*fac[i]%Mod*quick_power(n+1,n-i,Mod))%Mod;
	}
	printf("%d\n",ans);
	return 0;
}