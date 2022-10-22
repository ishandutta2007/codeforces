#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%lld",a)
const int o=5e6+10,O=2e5+10;
#define int long long
int n,m,p[O],k[O],b[O],w[O],a[o],t[o],ans[o],seed,base,s[3],opt=1,S;
inline int rnd(){
	int ret=seed;
	seed=(seed*base+233)%1000000007;
	return ret;
}
signed main(){
	read(n);read(m);for(int i=1;i<=m;++i) read(p[i]),read(k[i]),read(b[i]),read(w[i]);
	for(int i=1;i<=m;++i){
		seed=b[i];base=w[i];
		for(int j=p[i-1]+1;j<=p[i];++j) t[j]=(rnd()%2)+1,a[j]=(rnd()%k[i])+1;
	}
	for(int i=1;i<=n;++i) s[t[i]]+=a[i];
	if(s[t[1]]>s[3-t[1]])
	{--a[1];++ans[1];for(int i=1,j=1;j<=n*2;i=i%n+1,++j) if(t[i]^t[1]) S+=a[i],ans[i]+=a[i],a[i]=0;else if(S>=a[i]) ans[i]+=a[i],S-=a[i],a[i]=0;else a[i]-=S,ans[i]+=S,S=0;}
	else for(int i=1,j=1,S=0;j<=n*2;i=i%n+1,++j) if(t[i]==t[1]) S+=a[i],ans[i]+=a[i],a[i]=0;else if(S>=a[i]) ans[i]+=a[i],S-=a[i],a[i]=0;else a[i]-=S,ans[i]+=S,S=0;
	for(int i=1;i<=n;++i) opt=((ans[i]^(i*1ll*i))+1)%1000000007*opt%1000000007;
	write(opt);
	return 0;
}