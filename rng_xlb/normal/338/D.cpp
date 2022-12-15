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
#define M 600200
namespace CALC2{
	inline LL add(LL x,LL y,LL mod){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline LL mns(LL x,LL y,LL mod){return (x-y<0)?(x-y+mod):(x-y);}
	inline void upd(LL &x,LL y,LL mod){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(LL &x,LL y,LL mod){x=(x-y<0)?(x-y+mod):(x-y);}
	inline LL mul(LL x,LL y,LL mod){return ((x*y-(LL)((LDB)x*(LDB)y/(LDB)mod)*mod)%mod+mod)%mod;}
} using namespace CALC2;
inline void exgcd(LL x,LL y,LL &tx,LL &ty,LL mod){
	if(!y){tx=1,ty=0;return;} exgcd(y,x%y,ty,tx,mod);
	dec(ty,mul(tx,x/y,mod),mod); 
}
LL n,m,mx,X;
LL A[M],B[M]; int K;
inline bool EXCRT(LL rm,LL lm){
	LL a=0,b=0,w=__gcd(lm,mx),mod=(mx/w)*lm; exgcd(mx,lm,a,b,mod);
	if(abs(rm-X)%w>0){puts("NO");return false;}
	LL kt=abs(rm-X)/w; kt%=mod; if(rm<X) kt=mns(0,kt,mod); a=mul(a,kt,mod);
	X=add(mul(a,mx,mod),X,mod),mx=mod; return true;
}
int main(){
	n=read(),m=read(),K=read(); LL rem=n;
	for(int i=0;i<K;i++) A[i]=read(); mx=1,rem=n;
	for(int i=0;i<K&&rem>0;i++){
		LL w=__gcd(mx,A[i]);
		rem/=(A[i]/w),mx*=A[i]/w;
	} if(!rem){puts("NO");return 0;}
	for(int i=0;i<K;i++) B[i]=mns(0,i%A[i],A[i]); mx=1,X=0;
	for(int i=0;i<K;i++) if(!EXCRT(B[i],A[i])) return 0; if(!X) X=mx;
	if(X+K-1>m){puts("NO");return 0;}
	for(int i=0;i<K;i++) if(__gcd(X+i,mx)!=A[i]){puts("NO");return 0;}
	puts("YES"); return 0;
}