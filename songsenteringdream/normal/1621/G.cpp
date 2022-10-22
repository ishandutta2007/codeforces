#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int o=2e5+10,MOD=1e9+7;
int T,n,a[o],c[o],b[o],f[o],g[o],v[o],st[o],tp;map<int,int> mp;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]=(b[pos]+val)%MOD;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res=(res+b[pos])%MOD;return res;}
inline void slv(){
	int res=tp=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),c[i]=a[i];
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i) mp[c[i]]=i;
	for(int i=1;i<=n;b[i++]=0) a[i]=(mp[a[i]]--);
	for(int i=1;i<=n;++i) modify(a[i],f[i]=(query(a[i])+1)%MOD);
	for(int i=1;i<=n;b[i++]=0) c[a[i]]=i;
	for(int i=n;i;--i) modify(n-a[i]+1,g[i]=(query(n-a[i]+1)+1)%MOD);
	for(int i=1;i<=n;b[i++]=0) v[i]=g[i];
	for(int i=n,mx=0;i;--i) if(a[i]>mx) mx=a[st[++tp]=i];
	for(int i=0;i<tp;modify(n-st[++i]+1,-1)){
		modify(n-st[i+1]+1,1);
		for(int j=a[st[i+1]]-1;j>a[st[i]];--j) modify(n-c[j]+1,v[c[j]]=query(n-c[j]+1));
		for(int j=a[st[i+1]]-1;j>a[st[i]];--j) modify(n-c[j]+1,-v[c[j]]);
	}
	for(int i=1;i<=n;++i) res=(res+f[i]*1ll*(g[i]-v[i]))%MOD;
	printf("%d\n",(res+MOD)%MOD);
}
int main(){for(scanf("%d",&T);T--;slv()) scanf("%d",&n);}