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

const int N=200005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll) ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}
struct node{int to,next,w;}p[N*2];
int n,m,tot,head[N],a[N],mu[N],phi[N],pri[N],vis[N];
int f[N][20],num[N],dep[N],bnd[N],si[N];
int S,b[N],c[N*2],ans,res,fa[N];
vi v[N],g[N];
void add(int x,int y,int z){p[++tot]=(node){y,head[x],z};head[x]=tot;}
void pre(){
	mu[1]=phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pri[++tot]=i,phi[i]=i-1,mu[i]=1;
		for(int j=1;j<=tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			mu[i*pri[j]]=mu[i];phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			v[j].pb(i);
}
void pre_dfs(int x){
	vis[x]=1;num[x]=++tot;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		dep[y]=dep[x]+1;
		f[y][0]=x;pre_dfs(y);
	}
	bnd[x]=tot;
}
void dfs(int x){
	si[x]=b[x];
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		dfs(y);ch(si[x],si[y]);
		ch(res,(ll)si[y]*(S-si[y]+mod)%mod*p[i].w%mod);
	}
}
inline bool cmp(int x,int y){return num[x]<num[y];}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=0;i<20;i++)
		if((dep[x]-dep[y])&(1<<i)) x=f[x][i];
	if(x==y) return x;
	for(int i=19;~i;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&n);
	pre();tot=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y,1);add(y,x,1);
	}
	clr(vis,0);tot=0;
	pre_dfs(1);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[a[i]].size();j++)
			g[v[a[i]][j]].pb(i);
	clr(head,0);tot=0;
	for(int i=1;i<=n;i++){
		if(!mu[i]) continue;
//		printf("%d\n",i);
		m=g[i].size();S=tot=0;
		if(m<2) continue;
		for(int j=1;j<=m;j++)
			c[j]=g[i][j-1],b[c[j]]=phi[a[c[j]]],ch(S,b[c[j]]);
		sort(c+1,c+m+1,cmp);
		for(int j=1;j<g[i].size();j++)
			c[++m]=lca(c[j],c[j+1]);
		sort(c+1,c+m+1,cmp);
		int t=m,now=c[1];m=1;
		for(int j=2;j<=t;j++)
			if(c[j]!=c[j-1]) c[++m]=c[j];
		for(int j=2;j<=m;j++){
			while(num[c[j]]>bnd[now]) now=fa[now];
			add(now,c[j],dep[c[j]]-dep[now]);
			fa[c[j]]=now;now=c[j];
		}
		res=0;dfs(c[1]);
		ch(ans,(ll)res*exp(phi[i],mod-2)%mod);
		for(int j=1;j<=m;j++) head[c[j]]=b[c[j]]=0;
//		debug(ans);
	}
//	debug(ans);
	ans=(ll)ans*exp((ll)n*(n-1)/2%mod,mod-2)%mod;
	printf("%d\n",ans);
//	printf("%lld %lld\n",549116751ll*229*114%mod,425773453ll*229*114%mod);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}