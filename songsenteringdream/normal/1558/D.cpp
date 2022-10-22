#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=5e5+10,MOD=998244353;
#define int long long
int T,n,m,a[o],x[o],y[o],fac[o],inv[o],s1[o],t1,s2[o],t2,c;bool vis[o];
inline int C(int x,int y){return fac[x]*inv[x-y]%MOD*inv[y]%MOD;}
inline void modify(int pos,int val){for(;pos<=n;pos+=(pos&-pos)) a[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=(pos&-pos)) res+=a[pos];return res;}
inline int kth(int k){
	int l=1,r=n,md;
	while(l<r) md=l+r>>1,(md-query(md)>=k?(r=md):(l=md+1));
	return l;
}
signed main(){
	inv[1]=1;for(int i=2;i<o;++i) inv[i]=MOD-MOD/i*inv[MOD%i]%MOD;
	for(int i=fac[0]=inv[0]=1;i<o;++i) fac[i]=fac[i-1]*i%MOD,inv[i]=inv[i-1]*inv[i]%MOD;
	for(read(T);T--;printf("%lld\n",C(2*n-1-c,n)),c=0){
		read(n);read(m);
		for(int i=1;i<=m;++i) read(x[i]),read(y[i]);
		for(int i=m,p,q;i;--i)
			p=kth(y[i]),q=kth(y[i]+1),(!vis[q]&&(vis[s1[++t1]=q]=1,++c)),modify(s2[++t2]=p,1);
		for(;t1;--t1) vis[s1[t1]]=0;
		for(;t2;--t2) modify(s2[t2],-1);
	}
	return 0;
}