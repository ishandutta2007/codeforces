#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 998244353
#define MN 100005
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
const int G=3,invG=(Mod+1)/3;
int A[MN*6],B[MN*6],r[MN*6];
void NTT(int *f,int n,int op){
	for(int i=0;i<n;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1;len<n;len<<=1){
		int p=len<<1,w=ksm(op?G:invG,(Mod-1)/p);
		for(int i=0;i<n;i+=p){
			int tmp=1;
			for(int l=i;l<i+len;++l){
				int TMP=f[l+len]*tmp%Mod;
				f[l+len]=(f[l]-TMP+Mod)%Mod;
				f[l]=(f[l]+TMP)%Mod;
				tmp=tmp*w%Mod;
			}
		}
	}
	if(!op){
		int inv=ksm(n,Mod-2);
		for(int i=0;i<n;++i)f[i]=f[i]*inv%Mod;
	}
}
int n,m,f[MN],fac[MN],dfac[MN],inv[MN];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<=n;++i)scanf("%lld",&f[i]);
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	int len=1;
	while(len<=n*3)len<<=1;
	for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)?(len>>1):0);
	for(int i=0;i<=n;++i)A[i]=f[i]*fac[i]%Mod;
	for(int i=0;i<=n;++i){
		B[i]=dfac[n-i];
	}
	NTT(A,len,1);NTT(B,len,1);
	for(int i=0;i<len;++i)A[i]=A[i]*B[i]%Mod;
	NTT(A,len,0);
	for(int i=0;i<=n;++i){
		A[i]=A[i+n]*dfac[i]%Mod;
	}
	for(int i=n+1;i<len;++i)A[i]=0;
	for(int i=0;i<=n;++i){
		A[i]=A[i]*ksm(ksm(i+1,m),Mod-2)%Mod;
		A[i]=A[i]*fac[i]%Mod;
	}
	for(int i=0;i<=n;++i){
		B[i]=dfac[n-i];
		if((n-i)&1)B[i]=Mod-B[i];
	}
	for(int i=n+1;i<len;++i)B[i]=0;
	NTT(A,len,1);NTT(B,len,1);
	for(int i=0;i<len;++i)A[i]=A[i]*B[i]%Mod;
	NTT(A,len,0);
	for(int i=0;i<=n;++i)printf("%lld ",A[i+n]*dfac[i]%Mod);
	return 0;
}