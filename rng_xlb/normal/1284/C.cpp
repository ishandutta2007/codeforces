#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}

int mod;
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 300200
int n,fac[M],ifac[M],ans;
inline int C(int N,int K){return mul(fac[N],mul(ifac[N-K],ifac[K]));}
int main(){
	n=read(),mod=read(),fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i); ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;--i) ifac[i-1]=mul(ifac[i],i);
	for(int i=1;i<=n;i++){
		int bas=mul(n-i+1,n-i+1);
		upd(ans,mul(bas,mul(fac[i],fac[n-i])));
	}
	printf("%d\n",ans);
	return 0;
}