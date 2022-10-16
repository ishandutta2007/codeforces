#include <cstdio>
#include <algorithm>
using namespace std;
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
const int Mod=998244353;
const int G=3;
const int Maxn=(1<<15);
int n,k;
void NTT(int *a,int flag,int n){
	static int R[Maxn<<2|5],last_len=0;
	int len=1,L=0;
	while(len<n){
		len<<=1;
		L++;
	}
	if(len!=last_len){
		last_len=len;
		for(int i=0;i<len;i++){
			R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		}
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
void mul(int *a,int *b,int *c){
	static int A[Maxn<<2|5],B[Maxn<<2|5];
	for(int i=0;i<=k;i++){
		A[i]=a[i];
		B[i]=b[i];
	}
	int len=1;
	while(len<=(k<<1)){
		len<<=1;
	}
	for(int i=k+1;i<=len;i++){
		A[i]=B[i]=0;
	}
	NTT(A,1,len);
	NTT(B,1,len);
	for(int i=0;i<len;i++){
		A[i]=1ll*A[i]*B[i]%Mod;
	}
	NTT(A,-1,len);
	for(int i=0;i<=k;i++){
		c[i]=A[i];
	}
}
int f[3][Maxn+5];
void add_1(){
	static int g[3][Maxn+5];
	for(int i=0;i<2;i++){
		for(int j=0;j<=k;j++){
			g[i][j]=f[i+1][j];
		}
	}
	for(int i=0;i<=k;i++){
		g[2][i]=f[2][i];
	}
	for(int i=1;i<=k;i++){
		g[2][i]=(g[2][i]+f[2][i-1])%Mod;
	}
	for(int i=1;i<=k;i++){
		g[2][i]=(g[2][i]+f[1][i-1])%Mod;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=g[i][j];
		}
	}
}
void mul_2(){
	static int g[3][Maxn+5],h[Maxn+5];
	for(int i=0;i<3;i++){
		for(int j=0;j<=k;j++){
			g[i][j]=0;
		}
	}
	mul(f[2],f[2],h);
	for(int i=0;i<=k;i++){
		g[2][i]=(g[2][i]+h[i])%Mod;
	}
	mul(f[1],f[1],h);
	for(int i=1;i<=k;i++){
		g[2][i]=(g[2][i]+h[i-1])%Mod;
	}
	for(int i=0;i<=k;i++){
		g[0][i]=(g[0][i]+h[i])%Mod;
	}
	mul(f[0],f[0],h);
	for(int i=1;i<=k;i++){
		g[0][i]=(g[0][i]+h[i-1])%Mod;
	}
	mul(f[2],f[1],h);
	for(int i=0;i<=k;i++){
		g[1][i]=(g[1][i]+h[i])%Mod;
	}
	mul(f[1],f[0],h);
	for(int i=1;i<=k;i++){
		g[1][i]=(g[1][i]+h[i-1])%Mod;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<=k;j++){
			f[i][j]=g[i][j];
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	int len=1,L=0;
	while(len<=n){
		len<<=1;
		L++;
	}
	f[1][0]=1;
	f[2][0]=f[2][1]=1;
	for(int i=L-2;i>=0;i--){
		mul_2();
		
		if((n>>i)&1){
			add_1();
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d ",f[2][i]);
	}
	puts("");
	return 0;
}