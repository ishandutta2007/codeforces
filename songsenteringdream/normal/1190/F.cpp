#include<cstdio>
using namespace std;
int n;long long y,m,p,phi,g,ord,st[1<<20],tp;bool vis[1<<23];
	namespace Pollard_Rho{
const int pri[]={2,3,5,7,11,13,17,19,23,29};
inline long long qm(long long a,long long b,long long mod){
	__int128 res=a;res=res*b%mod;return res;
}
inline long long qp(long long a,long long b,long long mod){
	long long res=1;
	for(;b;b>>=1,a=qm(a,a,mod)) if(b&1) res=qm(res,a,mod);
	return res;
}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long sd1=1000000007,sd2=1000000009,ans[300],cnt;int T;
inline long long rnd(){sd1=sd1*114519%998244353;sd2=sd2*100001%998244353;return (sd1<<28)|sd2;}
inline bool MillerRabin(long long x){
	if(x<3||!(x&1)) return x==2;
	int s=0;long long t,c,z;
	for(long long i=2;(x-1)%i==0;i<<=1) ++s,t=(x-1)/i;
	for(int i=0;i<10;++i){
		if(x==pri[i]) return true;
		c=qp(pri[i],t,x);
		for(int j=1;j<=s&&c>1;++j,c=z)
			if((z=qm(c,c,x))==1&&c!=x-1) return false;
		if(c!=1) return false;
	}
	return true;
}
inline long long f(long long x,long long c,long long mod){return (qm(x,x,mod)+c)%mod;}
inline long long PollardRho(long long x){
	int stp,gl=1;
	for(long long s=0,t=0,c=rnd()%(x-1)+1,val=1,d;1;gl<<=1,s=t,val=1){
		for(stp=1;stp<=gl;++stp){
			t=f(t,c,x);val=qm(val,t>s?t-s:s-t,x);
			if((stp%127)==0) if((d=gcd(val,x))>1) return d;
		}
		if((d=gcd(val,x))>1) return d;
	}
}
void slv(long long x){
	if(x<2) return;
	if(MillerRabin(x)){ans[++cnt]=x;return;}
	long long p=x;
	for(;p==x;p=PollardRho(x));
	for(;!(x%p);x/=p);
	slv(x);slv(p);
}
inline void fact(long long x){cnt=0;slv(x);}
	}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
inline long long qp(__int128 b,long long f){long long res=1;for(;f;f>>=1,b=b*b%m) if(f&1) res=res*b%m;return res;}
int main(){
	scanf("%d%lld%lld",&n,&m,&y);Pollard_Rho::fact(m);p=Pollard_Rho::ans[1];
	if(m<(1<<23)){
		vis[y]=1;
		for(long long i=y*y%m;i-y&&i;i=(__int128)i*y%m) vis[i]=1;
		for(int i=2;i<m&&tp<n;++i) if(!vis[i]&&i%p) st[++tp]=i;
	}
	else if(y%p==0){for(long long i=2;i<m&&tp<n;++i) if(i%p) st[++tp]=i;}
	else if(p>2){
		Pollard_Rho::fact(ord=phi=m/p*(p-1));
		for(int i=1;i<=Pollard_Rho::cnt;++i) if(qp(y,ord/Pollard_Rho::ans[i])==1){ord/=Pollard_Rho::ans[i];break;}
		if(ord<phi){
			g=2;
			for(bool flg;1;++g){
				flg=1;
				for(int i=1;i<=Pollard_Rho::cnt&&flg;++i) flg=(qp(g,phi/Pollard_Rho::ans[i])>1);
				if(flg) break;
			}
			for(long long v=g,i=1;tp<n;++i,v=(__int128)v*g%m) if(i%(phi/ord)) st[++tp]=v;
		}
	}
	else for(long long i=1;i<m&&tp<n;i+=2) if(i%8!=1&&i%8!=y%8) st[++tp]=i;
	if(tp<n) printf("-1");
	else for(int i=1;i<=n;++i) printf("%lld ",st[i]);
	return 0;
}