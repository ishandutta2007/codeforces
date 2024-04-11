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
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next;}p[N<<2];
int n,m,root,tot,head[N],dp[N],si[N],cnt[N],fa[N],dia[N];
vi g[N],f[N];
bool vis[N];
vector<double> sum[N];
map<int,double> res[N];
void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;
}
void dfs(int x){
//	debug(x);
	vis[x]=1;fa[x]=root;si[root]++;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y])continue;
		dfs(y);gmax(dp[x],dp[y]+1);
	}
}
void dfs2(int x,int k){
	vis[x]=1;gmax(dp[x],k);
	int mx=0,mx2=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		if(mx<dp[y]+1) mx2=mx,mx=dp[y]+1; else if(dp[y]+1>mx2) mx2=dp[y]+1;
	}
//	printf("%d %d %d\n",x,mx,mx2);
	gmax(dia[root],mx+mx2);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,ky=k;
		if(vis[y]) continue;
		if(dp[y]+1==mx) gmax(ky,mx2); else gmax(ky,mx);
		dfs2(y,ky+1);
	}
}
double solve(int x,int y){
	if(si[x]>si[y]) swap(x,y);
	if(res[x].count(y)) return res[x][y];
	double &ans=res[x][y];ans=0;
	int d=max(dia[x],dia[y]);
//	debug(d);
	int st=lower_bound(g[y].begin(),g[y].end(),d-g[x][0])-g[y].begin();
	for(int i=0;i<cnt[x];i++){
//		printf("%d %d %d\n",g[x][i],g[y][st-1],g[x][i]+g[y][st-1]+1);
		while(st>0&&g[x][i]+g[y][st-1]+1>d) st--;
//		debug(st);
		if(st) ans+=((double)f[y][st-1]*(d-g[x][i]-1)-sum[y][st-1])*(f[x][i]-(i?f[x][i-1]:0));
		ans+=(double)(sum[y][cnt[y]-1]+(double)(g[x][i]+1)*si[y])*(f[x][i]-(i?f[x][i-1]:0));
//		debug(ans);
	}
//	debug(ans);
	ans=ans/si[x]/si[y];
	return ans;
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) root=i,dfs(i);
	clr(vis,0);
	for(int i=1;i<=n;i++) 
		if(!vis[i]) root=i,dfs2(i,0);
	for(int i=1;i<=n;i++)
		g[fa[i]].pb(dp[i]);
//	debuge;
	for(int i=1;i<=n;i++){
		if(!g[i].size()) continue;
//		for(int j=0;j<g[i].size();j++) printf("%d ",g[i][j]);puts("");
		vi tmp=g[i];sort(tmp.begin(),tmp.end());
//		debug(i);
		g[i].clear();cnt[i]=1;
		g[i].pb(tmp[0]);f[i].pb(1);
//		debug(i);
		for(int j=1;j<tmp.size();j++){
			if(tmp[j]!=g[i][cnt[i]-1]) ++cnt[i],g[i].pb(tmp[j]),f[i].pb(0);
			f[i][cnt[i]-1]++;
		}
		sum[i].resize(cnt[i]);
		sum[i][0]=(double)g[i][0]*f[i][0];
//		debug(i);
		for(int j=1;j<cnt[i];j++) sum[i][j]=sum[i][j-1]+(double)g[i][j]*f[i][j],f[i][j]+=f[i][j-1];
//		debug(i);
//		for(int j=0;j<cnt[i];j++) printf("%d %d\n",g[i][j],(int)sum[i][j]);
	}
//	debuge;
	while(Q--){
		int x,y;scanf("%d%d",&x,&y);
		x=fa[x];y=fa[y];
		if(x==y) puts("-1"); else printf("%.9f\n",solve(x,y));
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}