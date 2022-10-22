#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
const int MN = 800005,Mod=998244353; 
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
const int G=3,invG=ksm(3,Mod-2);
int n,m;
int subupd(register int a){if(a>=0)return a;return a+Mod;}
int addupd(register int a){if(a<Mod)return a;return a-Mod;}
LL a[MN],b[MN],A[MN],B[MN],r[MN],c[MN];
void NTT(LL *f,int n,int op){
	for(int i=0;i<n;++i)
		if(i<r[i])swap(f[i],f[r[i]]);
	for(int len=1,p=2;len<n;len<<=1,p<<=1){
		LL tmp=ksm(op?G:invG,(Mod-1)/p);
		for(int i=0;i<n;i+=p){
			LL buf=1;
			for(int l=i;l<i+len;++l){
				LL TMP=buf*f[l+len]%Mod;
				f[l+len]=subupd(f[l]-TMP);
				f[l]=addupd(f[l]+TMP);
				buf=buf*tmp%Mod;
			}
		}
	}
	if(!op){
		int inv=ksm(n,Mod-2);
		for(int i=0;i<n;++i)
			f[i]=f[i]*inv%Mod;
	}
}
void INV(int n,LL *a,LL *b){
	if(n==1){
		b[0]=ksm(a[0],Mod-2);
		return;
	}
	INV(n+1>>1,a,b);
	int len=1;
	while(len<=n*2)len<<=1;
	for(int i=0;i<len;++i)
		r[i]=(r[i>>1]>>1)|((i&1)?(len>>1):0);
	for(int i=0;i<n;++i)c[i]=a[i];
	for(int i=n;i<len;++i)c[i]=0;
	NTT(c,len,1);NTT(b,len,1);
	for(int i=0;i<len;++i)
		b[i]=(2ll-c[i]*b[i]%Mod+Mod)*b[i]%Mod;
	NTT(b,len,0);
	for(int i=n;i<len;++i)b[i]=0;
}
void dao(int *a,int *b,int n){
	for(int i=1;i<n;++i)b[i-1]=a[i]*i%Mod;b[n-1]=0;
}
void jifen(int *a,int *b,int n){
	for(int i=1;i<n;++i)b[i]=a[i-1]*ksm(i,Mod-2)%Mod;b[0]=0;
}
int init(int len){
	int n=1;
	while(n<=len)n<<=1;
	for(int i=0;i<n;++i)r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
	return n;
}
void LN(int *a,int *b,int n){
	dao(a,A,n);INV(n,a,B);
	int l=init(n);NTT(A,l,1);NTT(B,l,1);
	for(int i=0;i<l;++i)A[i]=A[i]*B[i]%Mod;
	NTT(A,l,0);jifen(A,b,n);
}
int f[MN],g[MN],ans[MN];
void pre(int n){
	for(int i=0;i<n;++i)r[i]=(r[i>>1]>>1)|((i&1)?(n>>1):0);
}
void work(int l,int r){
	if(l+1==r){
		if(l)g[l]=g[l]*ksm(l,Mod-2)%Mod;
		else g[l]=1;
		return;
	}
	int mid=(l+r)>>1;
	work(l,mid);
	int len=1;
	while(len<=r-l)len<<=1;
	for(int i=0;i<len;++i){
		a[i]=b[i]=0;
	}
	pre(len);
	for(int i=l;i<mid;++i)a[i-l]=g[i];
	for(int i=0;i<r-l-1;++i)b[i]=f[i];
	NTT(a,len,1);NTT(b,len,1);
	for(int i=0;i<len;++i)a[i]=a[i]*b[i]%Mod;
	NTT(a,len,0);
	for(int i=mid-1-l;i<r-l-1;++i)
		g[i+l+1]=(g[i+l+1]+a[i])%Mod;
	work(mid,r);
}
void sqrt(int *a,int n){
	int len=1;while(len<=n)len<<=1;
	LN(a,b,len);
	int inv2=ksm(2,Mod-2);
	for(int i=0;i<n;++i)f[i]=b[i]*inv2%Mod;
	for(int i=1;i<n;++i)f[i-1]=f[i]*i%Mod;f[n-1]=0;
	work(0,n);
}
signed main(){
	n=read();m=read()+1;
	for(int i=1;i<=n;++i)a[read()]=Mod-4;
	a[0]=1;sqrt(a,m);
	g[0]++;
	INV(m,g,ans);
	for(int i=1;i<m;++i)printf("%lld\n",ans[i]*2%Mod);	
	return 0;
}