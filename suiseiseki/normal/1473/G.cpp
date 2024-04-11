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
const int Maxn=20000;
const int Maxm=200000;
const int G=3;
void NTT(int *a,int flag,int n){
	static int R[Maxn+5],last_len;
	int len=1,L=0;
	while(len<n){
		len<<=1;
		L++;
	}
	if(last_len!=len){
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
int frac[Maxm+5],inv_f[Maxm+5];
void init(){
	frac[0]=1;
	for(int i=1;i<=Maxm;i++){
		frac[i]=1ll*frac[i-1]*i%Mod;
	}
	inv_f[Maxm]=quick_power(frac[Maxm],Mod-2,Mod);
	for(int i=Maxm-1;i>=0;i--){
		inv_f[i]=1ll*inv_f[i+1]*(i+1)%Mod;
	}
}
int C(int n,int m){
	return 1ll*frac[n]*inv_f[m]%Mod*inv_f[n-m]%Mod;
}
void mul(int *a,int a_len,int *b,int b_len,int *c){
	static int A[Maxn+5],B[Maxn+5];
	for(int i=0;i<a_len;i++){
		A[i]=a[i];
	}
	for(int i=0;i<b_len;i++){
		B[i]=b[i];
	}
	int len=1;
	while(len<(a_len+b_len-1)){
		len<<=1;
	}
	for(int i=a_len;i<len;i++){
		A[i]=0;
	}
	for(int i=b_len;i<len;i++){
		B[i]=0;
	}
	NTT(A,1,len);
	NTT(B,1,len);
	for(int i=0;i<len;i++){
		A[i]=1ll*A[i]*B[i]%Mod;
	}
	NTT(A,-1,len);
	for(int i=0;i<a_len+b_len-1;i++){
		c[i]=A[i];
	}
}
int A[Maxn+5],B[Maxn+5],tmp[Maxn+5];
int a_len,b_len,c_len;
int main(){
	init();
	int n;
	scanf("%d",&n);
	a_len=1;
	A[0]=1;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		b_len=(a_len<<1)+20;
		for(int i=0;i<b_len;i++){
			B[i]=0;
		}
		for(int i=0;i<b_len;i++){
			int id=i-(a_len+10)+b;
			B[i]=C(a+b,id);
		}
		mul(A,a_len,B,b_len,A);
		for(int i=0;i<a_len+a-b;i++){
			tmp[i]=0;
		}
		for(int i=0;i<a_len+b_len-1;i++){
			int id=(i-(a_len+10));
			if(id>=0&&id<a_len+a-b){
				tmp[id]=A[i];
			}
		}
		a_len+=a-b;
		for(int i=0;i<a_len;i++){
			A[i]=tmp[i];
		}
	}
	int ans=0;
	for(int i=0;i<a_len;i++){
		ans=(ans+A[i])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}