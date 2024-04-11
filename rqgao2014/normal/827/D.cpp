//get(x,p): wrong order with dep[x]&dep[p]
//find(x): without "fa[x]=find(fa[x])"
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

const int N=400005,M=100005,mod=1e9+7,B=18;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
template<class T>inline void read(T &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
template<class T>inline void print(T x,char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[10];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int x,y,z,num;}p[N];
struct edge{int to,next,w;}g[N<<1];
int tot,head[N],res[N],ans[N],bit[N];
int n,m,fa[N],dep[N],f[N][20],dp[N][20];
bool vis[N],tag[N];

inline int find(int x){return fa[x]!=x?fa[x]=find(fa[x]):x;}
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int add(int x,int y,int z){
	g[++tot]=(edge){y,head[x],z};head[x]=tot;
	g[++tot]=(edge){x,head[y],z};head[y]=tot;
}
inline void dfs(int x,int k,int w){
	f[x][0]=k;dp[x][0]=w;vis[x]=1;
	dep[x]=dep[k]+1;
	for(int i=head[x];i;i=g[i].next){
		int y=g[i].to;
		if(!vis[y]) dfs(y,x,g[i].w);
	}
}
inline int rise(int &x,int y){
	while(y) x=f[x][bit[y&-y]],y^=y&-y;
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	rise(x,dep[x]-dep[y]);
	if(x==y) return x;
	for(int i=B-1;~i;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline int get(int x,int p){
	int ans=0,y=dep[x]-dep[p];
	while(y){
		int k=bit[y&-y];
		gmax(ans,dp[x][k]),x=f[x][k];
		y^=1<<k;
	}
	return ans;
}
inline void make(int x,int k,int w){
	x=find(x);
	while(dep[x]>dep[k]){
		gmin(res[x],w);
		x=fa[x]=find(f[x][0]);
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	read(n);read(m);
	for(int i=0;i<B;i++) bit[1<<i]=i;
	for(int i=1;i<=m;i++)
		read(p[i].x),read(p[i].y),read(p[i].z),p[i].num=i;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(p[i].x),y=find(p[i].y);
		if(x!=y) fa[x]=y,add(p[i].x,p[i].y,p[i].z),tag[i]=1;
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++) fa[i]=i,res[i]=inf;
	for(int j=1;j<B;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1],dp[i][j]=max(dp[i][j-1],dp[f[i][j-1]][j-1]);
	for(int i=1;i<=m;i++)
		if(!tag[i]){
			int x=p[i].x,y=p[i].y,k=lca(x,y);
//			debug(k);
			make(x,k,p[i].z);make(y,k,p[i].z);
			ans[p[i].num]=max(get(x,k),get(y,k));
		}
	for(int i=1;i<=m;i++)
		if(tag[i]){
			int x=p[i].x,y=p[i].y;
			if(dep[x]<dep[y]) swap(x,y);
			ans[p[i].num]=res[x]<inf?res[x]:0;
		}
	for(int i=1;i<=m;i++) print(ans[i]-1,i<m?' ':'\n');
	return 0;
}