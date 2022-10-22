#include<bits/stdc++.h>
using namespace std;
#define MN 50005
#define int long long
#define Mod 998244353
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int n,S[MN],w0[MN],w1[MN],w2[MN];
int f00[MN],f01[MN],f10[MN],f11[MN];
int a[MN<<2],b[MN<<2],c[MN<<2],d[MN<<2],A[MN<<2],B[MN<<2],C[MN<<2],res[MN<<2],r[MN<<2];
void init(int len){
	for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)?(len>>1):0);
	for(int i=0;i<len;++i){
		a[i]=b[i]=c[i]=d[i]=0;
		A[i]=B[i]=C[i]=0;
		res[i]=0;
	}
}
const int G=3,invG=ksm(3,Mod-2);
int aupd(int a){return (a<Mod)?a:(a-Mod);}
int supd(int a){return (a>=0)?a:(a+Mod);}
void NTT(int *f,int n,int op){
	for(int i=0;i<n;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1;len<n;len<<=1){
		int p=len<<1,w=ksm(op?G:invG,(Mod-1)/p);
		for(int i=0;i<n;i+=p){
			int buf=1;
			for(int l=i;l<i+len;++l){
				int TMP=buf*f[l+len]%Mod;
				f[l+len]=supd(f[l]-TMP);
				f[l]=aupd(f[l]+TMP);
				buf=buf*w%Mod;
			}
		}
	}
	if(!op){
		int inv=ksm(n,Mod-2);
		for(int i=0;i<n;++i)f[i]=f[i]*inv%Mod;
	}
}
void cdqfft(int l,int r){
//	cerr<<"work: "<<l<<" "<<r<<endl;
	if(l==r){
		f00[l]=(f00[l]+w0[l]*l)%Mod;
		f01[l]=(f01[l]+w1[l]*l)%Mod;
		f10[l]=(f10[l]+w1[l]*l)%Mod;
		f11[l]=(f11[l]+w2[l]*l)%Mod;
//		cerr<<"done "<<l<<": "<<f00[l]<<" "<<f01[l]<<" "<<f10[l]<<" "<<f11[l]<<endl;
		return;
	}
	int mid=(l+r)>>1;
	cdqfft(l,mid);
	int n=mid-l,m=r-l,len=1;
	while(len<=n+m)len<<=1;
	init(len);
	for(int i=0;i<=m;++i){
		A[i]=w0[i];B[i]=w1[i];C[i]=w2[i];
	}
	for(int i=0;i<=n;++i){
		a[i]=f00[l+i];b[i]=f01[l+i];c[i]=f10[l+i];d[i]=f11[l+i];
	}
	NTT(a,len,1);NTT(b,len,1);NTT(c,len,1);NTT(d,len,1);
	NTT(A,len,1);NTT(B,len,1);NTT(C,len,1);

	for(int i=0;i<len;++i)res[i]=(A[i]*a[i]+b[i]*B[i])%Mod;
	NTT(res,len,0);
	for(int i=n+1;i<=m;++i)f00[i+l]=(f00[i+l]+res[i])%Mod;

	for(int i=0;i<len;++i)res[i]=(B[i]*a[i]+C[i]*b[i])%Mod;
	NTT(res,len,0);
	for(int i=n+1;i<=m;++i)f01[i+l]=(f01[i+l]+res[i])%Mod;
	
	for(int i=0;i<len;++i)res[i]=(A[i]*c[i]+B[i]*d[i])%Mod;
	NTT(res,len,0);
	for(int i=n+1;i<=m;++i)f10[i+l]=(f10[i+l]+res[i])%Mod;

	for(int i=0;i<len;++i)res[i]=(B[i]*c[i]+C[i]*d[i])%Mod;
	NTT(res,len,0);
	for(int i=n+1;i<=m;++i)f11[i+l]=(f11[i+l]+res[i])%Mod;
	cdqfft(mid+1,r);
}
signed main(){
	scanf("%lld",&n);
	S[0]=1;
	for(int i=2;i<=n;++i){
		S[i]=(S[i-2]+((i>3)?(S[i-4]):0))%Mod;
	}
	for(int i=2;i<=n;++i){
		w0[i]=S[i-1]*(i-1)%Mod*(i-1)%Mod;
		w1[i]=S[i-2]*(i-1)%Mod*(i-1)%Mod;
		if(i>2)w2[i]=S[i-3]*(i-1)%Mod*(i-1)%Mod;
	}
#ifdef dddakioi
	for(int i=2;i<=n;++i){
		for(int j=2;j<i-1;++j){
			f00[i]=(f00[i]+w0[j]*f00[i-j]+w1[j]*f01[i-j])%Mod;
			f01[i]=(f01[i]+w1[j]*f00[i-j]+w2[j]*f01[i-j])%Mod;
			f10[i]=(f10[i]+w0[j]*f10[i-j]+w1[j]*f11[i-j])%Mod;
			f11[i]=(f11[i]+w1[j]*f10[i-j]+w2[j]*f11[i-j])%Mod;
		}
		f00[i]=(f00[i]+w0[i]*i)%Mod;
		f01[i]=(f01[i]+w1[i]*i)%Mod;
		f10[i]=(f10[i]+w1[i]*i)%Mod;
		f11[i]=(f11[i]+w2[i]*i)%Mod;
	}
#endif
	cdqfft(1,n);
	printf("%lld\n",(f00[n]+f11[n])%Mod);
	return 0;
}