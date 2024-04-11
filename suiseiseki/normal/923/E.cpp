#include <cstdio>
#include <algorithm>
using namespace std;
template<typename Elem>
int quick_power(int a,Elem b,int Mod){
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
typedef long long ll;
const int Maxn=100000;
const int Mod=998244353;
const int G=3;
int p[Maxn+5];
int n;
ll m;
int frac[Maxn+5],inv_f[Maxn+5],inv[Maxn+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxn+1;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxn+1]=quick_power(frac[Maxn+1],Mod-2,Mod);
	for(int i=Maxn;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
	inv[1]=1;
	for(int i=2;i<=Maxn+1;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
void NTT(int *a,int flag,int n){
	static int R[Maxn<<2|5],last_len;
	int len=1,L=0;
	while(len<n){
		len<<=1;
		L++;
	}
	if(len!=last_len){
		for(int i=0;i<len;i++){
			R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		}
		last_len=len;
	}
	for(int i=0;i<len;i++){
		if(i<R[i]){
			swap(a[i],a[R[i]]);
		}
	}
	for(int j=1;j<len;j<<=1){
		int T=quick_power(G,(Mod-1)/(j<<1),Mod);
		for(int k=0;k<len;k+=(j<<1)){
			for(int l=0,t=1;l<j;l++,t=1ll*t*T%Mod){
				int Nx=a[k+l],Ny=1ll*t*a[j+k+l]%Mod;
				a[k+l]=(Nx+Ny)%Mod;
				a[j+k+l]=(Nx-Ny+Mod)%Mod;
			}
		}
	}
	if(flag==-1){
		reverse(a+1,a+len);
		for(int i=0,t=quick_power(len,Mod-2,Mod);i<len;i++){
			a[i]=1ll*a[i]*t%Mod;
		}
	}
}
int a[Maxn<<2|5],b[Maxn<<2|5],f[Maxn<<2|5],g[Maxn<<2|5];
int main(){
	init();
	scanf("%d%lld",&n,&m);
	for(int i=0;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=0;i<=n;i++){
		a[i]=inv_f[i];
		b[i]=1ll*frac[n-i]*p[n-i]%Mod;
	}
	int len=1;
	while(len<=(n<<1)){
		len<<=1;
	}
	NTT(a,1,len);
	NTT(b,1,len);
	for(int i=0;i<len;i++){
		a[i]=1ll*a[i]*b[i]%Mod;
	}
	NTT(a,-1,len);
	for(int i=0;i<=n;i++){
		g[i]=1ll*a[n-i]*inv_f[i]%Mod;
		g[i]=1ll*g[i]*quick_power(inv[i+1],m,Mod)%Mod;
	}
	for(int i=0;i<len;i++){
		a[i]=b[i]=0;
	}
	for(int i=0;i<=n;i++){
		if(i&1){
			a[i]=Mod-inv_f[i];
		}
		else{
			a[i]=inv_f[i];
		}
		b[i]=1ll*frac[n-i]*g[n-i]%Mod;
	}
	NTT(a,1,len);
	NTT(b,1,len);
	for(int i=0;i<len;i++){
		a[i]=1ll*a[i]*b[i]%Mod;
	}
	NTT(a,-1,len);
	for(int i=0;i<=n;i++){
		f[i]=1ll*a[n-i]*inv_f[i]%Mod;
	}
	for(int i=0;i<=n;i++){
		printf("%d ",f[i]);
	}
	puts("");
	return 0;
}