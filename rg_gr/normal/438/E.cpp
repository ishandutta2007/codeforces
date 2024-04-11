#include <bits/stdc++.h>
#define register
using namespace std;
#define int long long
const int maxn=400000+10;
const int mod=998244353;
const int inv2=499122177;
int n,f[maxn],g[maxn],A[maxn],B[maxn],C[maxn],D[maxn],r[maxn];

inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return (f==1)?x:-x;
}

int fpow(int a,int b){
	int ret=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1) ret=1ll*ret*a%mod;
	return ret;
}

void NTT(int *f,int n,int op){
	for(int i=0;i<n;i++)
		if(i<r[i]) swap(f[i],f[r[i]]);
	int buf,tmp,x,y;
	for(int len=1;len<n;len<<=1){
		tmp=fpow(3,(mod-1)/(len<<1));
		if(op==-1) tmp=fpow(tmp,mod-2);
		for(int i=0;i<n;i+=len<<1){
			buf=1;
			for(int j=0;j<len;j++){
				x=f[i+j];y=1ll*buf*f[i+j+len]%mod;
				f[i+j]=(x+y)%mod;f[i+j+len]=(x-y+mod)%mod;
				buf=1ll*buf*tmp%mod;
			}
		}
	}
	if(op==1) return ;
	int inv=fpow(n,mod-2);
	for(int i=0;i<n;i++) f[i]=1ll*f[i]*inv%mod;
}

void Inv(int *a,int *b,int n){
	b[0]=fpow(a[0],mod-2);
	int len,lim;
	for(len=1;len<(n<<1);len<<=1){
		lim=len<<1;
		for(int i=0;i<len;i++) A[i]=a[i],B[i]=b[i];
		for(int i=0;i<lim;i++) r[i]=(r[i>>1]>>1)|((i&1)?len:0);
		NTT(A,lim,1);NTT(B,lim,1);
		for(int i=0;i<lim;i++) b[i]=((2ll-1ll*A[i]*B[i]%mod)*B[i]%mod+mod)%mod;
		NTT(b,lim,-1);
		for(int i=len;i<lim;i++) b[i]=0;
	}
	for(int i=0;i<len;i++) A[i]=B[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

void Sqrt(int *a,int *b,int n){
	b[0]=1;
	int *A=C,*B=D,len,lim;
	for(len=1;len<(n<<1);len<<=1){
		lim=len<<1;
		for(int i=0;i<len;i++) A[i]=a[i];
		Inv(b,B,lim>>1);
		for(int i=0;i<lim;i++) r[i]=(r[i>>1]>>1)|((i&1)?len:0);
		NTT(A,lim,1);NTT(B,lim,1);
		for(int i=0;i<lim;i++) A[i]=1ll*A[i]*B[i]%mod;
		NTT(A,lim,-1);
		for(int i=0;i<len;i++) b[i]=1ll*(b[i]+A[i])%mod*inv2%mod;
		for(int i=len;i<lim;i++) b[i]=0;
	}
	for(int i=0;i<len;i++) A[i]=B[i]=0;
	for(int i=n;i<len;i++) b[i]=0;
}

signed main()
{
	int m=read();n=read()+1;
	for(int i=0;i<m;i++) f[read()]++;
	for(int i=0;i<n;i++)f[i]=(-4*f[i])%mod+mod,f[i]%=mod;
	f[0]++;f[0]%=mod;
	Sqrt(f,g,n);
	memset(f,0,sizeof(f));
	g[0]++,g[0]%=mod;
	Inv(g,f,n);
	for(int i=1;i<n;i++) printf("%lld\n",f[i]*2%mod);
	printf("\n");
	return 0;
}