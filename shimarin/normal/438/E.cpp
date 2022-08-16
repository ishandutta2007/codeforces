#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define poly vector<int>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}

namespace Poly{
	const int mod = 998244353;
	inline int Add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
	inline int Del(int a,int b){return a>=b?a-b:a+mod-b;}
	inline int power(int a,int b){
		int ret=1;
		for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
		return ret;
	}
	inline int Get(int x){
		int ret=1;
		while (ret<=x) ret<<=1;
		return ret;
	}
	vector<int>pos,w;
	#define rt register int
	inline void init(int n){
		pos.resize(n),w.resize(n);
		For(i,0,n-1) pos[i]=(pos[i>>1]>>1)|((i&1)*(n>>1));
		for (rt i=1;i<n;i<<=1){
			int wn=power(3,(mod-1)/i/2);w[i]=1;
			For(j,1,i-1) w[j+i]=1ll*w[j+i-1]*wn%mod;
		}
	}
	inline void DFT(poly &F,int n){
		F.resize(n);
		For(i,0,n-1) if (i<pos[i]) swap(F[i],F[pos[i]]);
		for (rt i=1;i<n;i<<=1)   	
            for (rt j=0;j<n;j+=i<<1)
        		for (rt k=0;k<i;k++){
        			int x=F[j+k],y=1ll*F[j+k+i]*w[i+k]%mod;
        			F[j+k]=Add(x,y),F[j+k+i]=Del(x,y);
        		}
	}
	inline void IDFT(poly &F,int n){
		DFT(F,n),reverse(F.begin()+1,F.end());
		for (rt i=0,inv=power(n,mod-2);i<n;i++) F[i]=1ll*F[i]*inv%mod;
	}
	inline poly Del(poly A,poly B){
		int n=max(A.size(),B.size());
		poly ret(n);A.resize(n),B.resize(n);
		For(i,0,n-1) ret[i]=Del(A[i],B[i]);
		return ret;
	}
	inline poly Mul(poly A,poly B){
		int n=A.size()+B.size()-1,m=Get(n);init(m);
		DFT(A,m),DFT(B,m);
		For(i,0,m-1) A[i]=1ll*A[i]*B[i]%mod;
		return IDFT(A,m),A.resize(n),A;
	}
	inline poly Inv(const poly &F,int n){
		if (n==1) return {power(F[0],mod-2)};
		poly G=Inv(F,n+1>>1),tmp(F.begin(),F.begin()+n);
		int m=Get(n*2-1);init(m);
		DFT(G,m),DFT(tmp,m);
		For(i,0,m-1) G[i]=1ll*Del(2,1ll*G[i]*tmp[i]%mod)*G[i]%mod;
		return IDFT(G,m),G.resize(n),G;
	}
	inline poly Derivation(poly F){
		int n=F.size();
		For(i,1,n-1) F[i-1]=1ll*F[i]*i%mod;
		return F.resize(n-1),F;
	}
	inline poly Integral(poly F){
		int n=F.size();F.resize(n+1);
		Dow(i,n,1) F[i]=1ll*F[i-1]*power(i,mod-2)%mod;
		return F[0]=0,F;
	}
	inline poly Ln(const poly &F,int n){
		poly tmp=Integral(Mul(Derivation(F),Inv(F,F.size())));
		return tmp.resize(n),tmp;
	}
	inline poly Exp(const poly &F,int n){
		if (n==1) return {1};
		poly G=Exp(F,n+1>>1);G.resize(n);
		poly ln=Ln(G,n),tmp=F,ret;
		ret=Del(tmp,ln),ret[0]=Add(ret[0],1),ret=Mul(ret,G);
		return ret.resize(n),ret;
	}
	inline poly Sqrt(const poly &F,int n){
		poly tmp=Ln(F,n);
		int inv=power(2,mod-2);
		For(i,0,n-1) tmp[i]=1ll*tmp[i]*inv%mod;
		return Exp(tmp,n);
	}
}

const int N = 1e5+10;
int n,m;
poly G;

int main(){
	n=read(),m=read(),G.resize(m+1);
	For(i,1,n){
		int x=read();
		if (x<=m) G[x]=1;
	}
	poly tmp(m+1);tmp[0]=1;
	For(i,1,m) tmp[i]=G[i]?Poly::mod-4:0;
	poly F=Poly::Sqrt(tmp,m+1);
	F[0]=Poly::Add(F[0],1);
	F=Poly::Inv(F,m+1);
	For(i,1,m) printf("%d\n",2ll*F[i]%Poly::mod);
}