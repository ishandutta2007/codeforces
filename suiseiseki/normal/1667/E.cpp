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
typedef unsigned long long ull;
const int Maxn=200000;
const int Mod=998244353;
const int G=3;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
namespace Poly{
	const int Maxf=(1<<19);
	int pow_G[Maxf+5];
	void init(){
		int len=Maxf;
		pow_G[len>>1]=1;
		int t=quick_power(G,(Mod-1)/len,Mod);
		for(int i=(len>>1)+1;i<len;i++){
			pow_G[i]=1ll*pow_G[i-1]*t%Mod;
		}
		for(int i=(len>>1)-1;i>0;i--){
			pow_G[i]=pow_G[i<<1];
		}
	}
	void NTT(int *a,int flag,int n){
		static int R[Maxf+5];
		static ull A[Maxf+5];
		int len=1,L=0;
		while(len<n){
			len<<=1,L++;
		}
		for(int i=0;i<len;i++){
			R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		}
		for(int i=0;i<len;i++){
			A[i]=a[R[i]];
		}
		for(int j=1;j<len;j<<=1){
			int *t=pow_G+j;
			for(int k=0;k<len;k+=(j<<1)){
				for(int l=0;l<j;l++){
					ull Nx=A[k+l],Ny=t[l]*A[j+k+l]%Mod;
					A[k+l]=Nx+Ny,A[j+k+l]=Nx+Mod-Ny;
				}
			}
		}
		for(int i=0;i<len;i++){
			a[i]=A[i]%Mod;
		}
		if(flag==-1){
			std::reverse(a+1,a+len);
			for(int i=0,t=find_inv(len);i<len;i++){
				a[i]=1ll*a[i]*t%Mod;
			}
		}
	}
	void poly_mul(int *a,int *b,int *c,int n){
		static int A[Maxf+5],B[Maxf+5];
		int len=1;
		while(len<=(n<<1)){
			len<<=1;
		}
		for(int i=0;i<=n;i++){
			A[i]=a[i],B[i]=b[i];
		}
		for(int i=n+1;i<len;i++){
			A[i]=B[i]=0;
		}
		NTT(A,1,len),NTT(B,1,len);
		for(int i=0;i<len;i++){
			A[i]=1ll*A[i]*B[i]%Mod;
		}
		NTT(A,-1,len);
		for(int i=0;i<=(n<<1);i++){
			c[i]=A[i];
		}
	}
}
int n;
int fac[Maxn+5],inv_f[Maxn+5],inv[Maxn+5];
void init(){
	fac[0]=1;
	for(int i=1;i<=Maxn;i++){
		fac[i]=1ll*fac[i-1]*i%Mod;
	}
	inv_f[Maxn]=find_inv(fac[Maxn]);
	for(int i=Maxn-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int val[Maxn+5];
int ans[Maxn+5];
void init_val(){
	static int f[Maxn<<1|5],g[Maxn+5];
	for(int i=0;i<=n;i++){
		f[i]=inv_f[n-i];
	}
	for(int i=(n-1)/2;i<=n-2;i++){
		g[n-i]=fac[n-2-i];
	}
	Poly::poly_mul(f,g,f,n);
	val[1]=1;
	for(int i=2;i<=n;i++){
		val[i]=1ll*fac[n-i]*f[n+i]%Mod*(i-1)%Mod*inv_f[n-1]%Mod;
	}
}
int main(){
	Poly::init();
	init();
	scanf("%d",&n);
	init_val();
	int sum=0;
	for(int i=n;i>0;i--){
		ans[i]=(val[i]-sum+Mod)%Mod;
		sum=(sum+1ll*inv[i-1]*val[i])%Mod;
	}
	for(int i=1;i<=n;i++){
		int tmp=1ll*ans[i]*fac[n-1]%Mod;
		printf("%d ",tmp);
	}
	puts("");
	return 0;
}