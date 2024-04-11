#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e6+10;
int T,n,m,cnt,a[o],b[o],p[o],c[o],d[o],tot;map<int,int> mp;long long ans;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos){for(;pos<=tot;pos+=lowbit(pos)) ++a[pos];}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=a[pos];return res;}
void slv(int l,int r,int lp,int rp){
	if(l>r) return;
	int md=l+r>>1;
	c[p[md]=lp]=d[rp]=0;
	for(int i=lp;i<rp;++i) c[i+1]=c[i]+(a[i]>b[md]);
	for(int i=rp;i>lp;--i) d[i-1]=d[i]+(a[i-1]<b[md]);
	for(int i=rp;i>lp;--i) if(c[i]+d[i]<c[p[md]]+d[p[md]]) p[md]=i;
	slv(l,md-1,lp,p[md]);slv(md+1,r,p[md],rp);
}
int main(){
	for(read(T);T--;printf("%lld\n",ans),mp.clear(),ans=cnt=tot=0){
		read(n);read(m);
		for(int i=1;i<=n;++i) read(a[i]);
		for(int i=1;i<=m;++i) read(b[i]);
		sort(b+1,b+m+1);slv(1,m,1,n+1);
		for(int i=1,j=1;i<=n+1;c[++cnt]=a[i++]) for(;j<=m&&p[j]<=i;c[++cnt]=b[j++]);
		for(int i=--cnt;i;--i) d[i]=c[i];
		sort(d+1,d+cnt+1);
		for(int i=1;i<=cnt;++i) if(d[i]^d[i-1]) mp[d[i]]=++tot;
		for(int i=1;i<=tot;++i) a[i]=0;
		for(int i=1;i<=cnt;modify(c[i++])) ans+=query((c[i]=tot+1-mp[c[i]])-1);
	}
	return 0;
}