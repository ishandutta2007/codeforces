#include<cstdio>
#include<iostream>
using namespace std;
const int o=6e5;
int T,n,m,cnt,ans[o];long long a[o],b[o],f[o],g[o];
#define NTT(MOD)\
inline int fix(int x){return x+(x>>31&MOD);}\
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%MOD) if(f&1) res=res*1ll*b%MOD;return res;}\
int w[o],rev[o],bt,a[o],b[o],F[o],sf[o],sf2[o],sg[o],sg2[o];\
inline void init(){\
	bt=19;\
	w[1<<(bt-1)]=1;\
	for(int i=(1<<(bt-1)),j=qp(3,(MOD-1)/(1<<bt));i<(1<<bt);++i) w[i+1]=w[i]*1ll*j%MOD;\
	for(int i=(1<<(bt-1));--i;) w[i]=w[i<<1];\
}\
inline void ntt(int*a,int n,bool inv){\
	for(int i=1;i<n;++i) if(rev[i]<i) swap(a[i],a[rev[i]]);\
	for(int md=1;md<n;md<<=1) for(int i=0;i<n;i+=md<<1) for(int j=0,x,y;j<md;++j)\
		x=a[i+j],y=a[i+j+md]*1ll*w[j+md]%MOD,a[i+j]=fix(x+y-MOD),a[i+j+md]=fix(x-y);\
	if(inv) for(int i=1,j=n-1;i<j;swap(a[i++],a[j--]));\
}\
inline void mul(){\
	if(n+m<32){\
		for(int i=0;i<=n;++i) F[i]=0;\
		for(int i=0;i<=n;++i) for(int j=max(0,m-i);j<=m;++j) F[i+j-m]=(F[i+j-m]+a[i]*1ll*b[j])%MOD;\
		return;\
	}\
	for(bt=0;(1<<bt)<=n+m;++bt);\
	for(int i=(1<<bt);i>n;--i) a[i]=0;\
	for(int i=(1<<bt);i>m;--i) b[i]=0;\
	for(int i=1;i<(1<<bt);++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bt-1));\
	ntt(a,1<<bt,0);ntt(b,1<<bt,0);\
	for(int i=0;i<(1<<bt);++i) a[i]=a[i]*1ll*b[i]%MOD;\
	ntt(a,1<<bt,1);\
	for(int i=m,j=qp((1<<bt),MOD-2);i<=n+m;++i) F[i-m]=a[i]*1ll*j%MOD;\
}\
inline void slv(){\
	for(int i=0;i<=n;++i) a[i]=f[i]%MOD;\
	for(int i=0;i<=m;++i) b[m-i]=g[i]%MOD;\
	mul();\
	for(int i=1;i<=n;++i) sf[i]=(sf[i-1]+f[i])%MOD,sf2[i]=(sf2[i-1]+f[i]%MOD*(f[i]%MOD))%MOD;\
	for(int i=1;i<=m;++i) sg[i]=(sg[i-1]+g[i])%MOD,sg2[i]=(sg2[i-1]+g[i]%MOD*(g[i]%MOD))%MOD;\
	for(int i=0;i<=n-m;++i) F[i]=(sf2[i+m]+MOD-sf2[i+2]+0ll+sf[i+m]+MOD-sf[i+2]+sg2[m]+MOD-sg[m]+2*(MOD-F[i]))%MOD;\
}
namespace MOD998244353{NTT(998244353)}
namespace MOD1004535809{NTT(1004535809)}
long long S(int x){return x*(x+1ll)/2;}
int main(){
	MOD998244353::init();MOD1004535809::init();
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=3;i<=n;++i) f[i]=a[i-2]+2*a[i-1]+a[i];
		scanf("%d",&m);
		for(int i=1;i<=m;++i) scanf("%lld",&b[i]);
		for(int i=3;i<=m;++i) g[i]=b[i-2]+2*b[i-1]+b[i];
		MOD998244353::slv();MOD1004535809::slv();
		for(int i=0;i<=n;++i)
			if(i+m>n){printf("-1");break;}
			else if(!MOD998244353::F[i]&&!MOD1004535809::F[i]){
				long long A=a[i+1]+a[i+2]-b[1]-b[2],B=b[1]-a[i+1];
				A+=(i+1)/2+1;B+=2*S((i+1)/2);
				if(A>=0&&A<=i+2&&S(A-1)<=B&&B<=S(i+1)-S(i-A+1)){
					cnt=0;
					for(int j=0;j<=i+1;++j)
						if(A&&j+S(i+1)-S(i-(A-1)+1)>=B){
							if(j&1) ans[++cnt]=i+2-j;
							--A;B-=j;
						}
						else if(j%2==0) ans[++cnt]=i+2-j;
					for(int j=3;j<=m;++j) if(f[i+j]^g[j]) ans[++cnt]=i+j;
					printf("%d\n",cnt);
					for(int j=1;j<=cnt;++j) printf("%d ",ans[j]);
					break;
				}
			}
	}
	return 0;
}