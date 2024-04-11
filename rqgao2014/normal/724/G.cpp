#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}
struct node{int to,next;ll w;}p[N<<2];
int n,m,tot,head[N],dep[N],ans;
ll cir[N<<2],f[N],a[65];
bool vis[N];
vi res;

inline void add(int x,int y,ll w){
	p[++tot]=(node){y,head[x],w};head[x]=tot;
	p[++tot]=(node){x,head[y],w};head[y]=tot;
}
inline void dfs(int x){
	vis[x]=1;res.pb(x);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]){
			if(dep[y]<dep[x]) cir[++tot]=f[x]^f[y]^p[i].w;
			continue;
		}
		f[y]=f[x]^p[i].w;
		dep[y]=dep[x]+1;dfs(y);
	}
}

void solve(){
	int sa=0,d=0,m=res.size();
	ll u=0;clr(a,0);
	for(int j=1;j<=tot;j++)
		for(int k=0;k<60;k++)
			if(cir[j]&(1ll<<k)){
				if(!a[k]){a[k]=cir[j];u|=a[k];sa++;break;} else cir[j]^=a[k];
			}
	ch(ans,u%mod*((1ll<<sa-1)%mod)%mod*((ll)m*(m-1)/2%mod)%mod);
	for(int i=0;i<60;i++){
		if(u&(1ll<<i)) continue;
		int c[2]={0,0};
		for(int j=0;j<m;j++)
			c[(f[res[j]]>>i)&1]++;
		ch(ans,(ll)c[0]*c[1]%mod*((1ll<<i)%mod)%mod*((1ll<<sa)%mod)%mod);
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);tot=1;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		res.clear();tot=0;
		dfs(i);solve();
	}
	printf("%d\n",ans);
	return 0;
}