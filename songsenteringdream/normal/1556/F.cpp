#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1<<14,lim=2e6+10,MOD=1e9+7;
#define int long long
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*b%MOD) if(f&1) res=res*b%MOD;return res;}
int n,a[o],inv[lim],f[o],ppc[o],ans,g[o];
inline int calc(int s1,int s2){
	int res=1;
	for(int i=1;i<=n;++i) if(s1&(1<<(i-1)))
		for(int j=1;j<=n;++j) if(s2&(1<<(j-1))) res=res*a[i]%MOD*inv[a[i]+a[j]]%MOD;
	return res;
}
signed main(){
	inv[1]=1;for(int i=2;i<lim;++i) inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
	read(n);for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<(1<<n);++i) f[i]=calc(i,i^((1<<n)-1));
	for(int i=1;i<(1<<n);++i) ppc[i]=ppc[i>>1]+(i&1);
	for(int i=1;i<(1<<n);++i){
		g[i]=f[i];
		for(int k=i&(i-1);k;k=i&(k-1)) g[i]=(g[i]-g[k]*calc(i^k,i^((1<<n)-1))%MOD+MOD)%MOD;
		ans=(ans+ppc[i]*g[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}