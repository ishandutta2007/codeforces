#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1e5+10,MOD=998244353;
#define int long long
int n,M,pri[o],mu[o],cnt,l[o],r[o],fac[o],t1[o],t2[o],m,f[o],s[o],ans;bool vis[o];
inline void linear_sieve(){
	mu[1]=1;
	for(int i=2;i<=M;++i){
		if(!vis[i]) mu[pri[++cnt]=i]=-1;
		for(int j=1;j<=cnt&&i*pri[j]<=M;++j){
			vis[i*pri[j]]=1;if(i%pri[j]==0) break;mu[i*pri[j]]=-mu[i];
		}
	}
}
inline int slv(){
	for(int i=1;i<=n;++i) if(r[i]<l[i]) return 0;else m-=l[i],r[i]-=l[i];
	if(m<0) return 0;
	for(int i=f[0]=s[0]=1;i<=m;++i) f[i]=s[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) s[j]=(s[j-1]+f[j])%MOD;
		for(int j=m;j;--j) f[j]=(s[j]-(j>r[i]?s[j-r[i]-1]:0))%MOD;
	}
	for(int i=1;i<=m;++i) f[i]+=f[i-1];
	return f[m]%MOD; 
}
signed main(){
	read(n);read(M);for(int i=1;i<=n;++i) read(t1[i]),read(t2[i]);linear_sieve();
	for(int i=1;i<=M;++i) if(mu[i]){
		for(int j=1;j<=n;++j) l[j]=(t1[j]+i-1)/i,r[j]=t2[j]/i;m=M/i;
		ans=(ans+slv()*mu[i])%MOD;
	}
	if(ans<0) ans+=MOD;write(ans);
	return 0;
}