//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <unordered_map>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rg_(i,x) for(int i=1;i<=(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Edge{
	int v,w,nxt;
}e[2000005];
int h[1000005],cnt=2;
int n,m,s,t,S,T;
void addedge(int u,int v,int w)
{
//	odb(u),odp(v,w);
	//w=min(w,n);
	e[cnt]=(Edge){v,w,h[u]};
	h[u]=cnt++;
}
int now[1000005];
int vis[2000005],dep[1000005];
int bfs(int s,int t)
{
	std::queue<int> q;
	memset(vis,0,sizeof(vis));
	vis[s]=1,dep[s]=0,now[s]=h[s];
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]||e[i].w==0)continue;
			dep[v]=dep[u]+1;
			now[v]=h[v];
			q.push(v);
			vis[v]=1;
			if(v==t)return 1;
		}
	}
	return 0;
}
int dfs(int u,int t,int f)
{
	if(u==t)return f;
	int l=f;
	for(int i=now[u];i;i=e[i].nxt)
	{
		now[u]=i;
		int v=e[i].v;
		if(e[i].w&&dep[v]==dep[u]+1)
		{
			int flow=dfs(v,t,e[i].w<l?e[i].w:l);
			e[i].w-=flow,e[i^1].w+=flow;
			l-=flow;
			if(l==0)break;
		}
	}
	return f-l;
}
inline void pig(int u,int v,int w,int c)
{
//if(w&&c)	
//odb(u),odp(v,w);
	addedge(u,v,w);
	addedge(v,u,0);
}
int fl[1000005];
//int n=read(),m=read(),flow=0,mincost=0,x,s=0,t=m+n+3,S=m+n+1,T=m+n+2,lxl=m+n+4;

inline void add(int u,int v,int l,int r,int c)
{
//	odb(u),odb(v),printf("[%d,%d]\n",l,r);
	pig(u,v,r-l,0);
	fl[u]-=l;
	fl[v]+=l;
//	mincost+=c*l;
}
const int inf=0x3f3f3f3f;
int qwq;
inline void rebuild()
{
	rg(n+n+2)fl[i]>0?qwq+=fl[i],pig(s,i,fl[i],0):pig(i,t,-fl[i],0);gr
	pig(T,S,inf,0);
}
int G[1005][1005];
int R[100005],C[100005];
std::unordered_map<int,int> mp2;
std::unordered_map<int,int> mp1;
int mp1_[100005],mp2_[100005];
//int mpa[100005],mpb[100005];
int la[100005],ra[100005],lb[100005],rb[100005];
int f[100005];
signed main()
{
	n=read(),m=read();S=n+n+1,T=S+1,s=T+1,t=s+1;int ff=0;
	int r=read(),b=read();if(r<b)r^=b^=r^=b,ff=1;
	//memset(mpa,0x3f,sizeof(mpa));
	//memset(mpb,0x3f,sizeof(mpb));
	rg(n)mp1[R[i]=read()]=i,mp2[C[i]=read()]=i;gr
	rg(n)mp1_[mp1[R[i]]]++,mp2_[mp2[C[i]]]++;gr
//	rg(n)odp(mp1_[i],mp2_[i]);gr
	rg(n)la[i]=lb[i]=0,ra[i]=mp1_[i],rb[i]=mp2_[i];gr
	rg(m)int op=read(),x=read(),d=read();
	if(op==1){if(!mp1.count(x))continue;
	x=mp1[x];//mp1_[x]++;
	int l=mp1_[x]-d+1>>1,r=mp1_[x]+d>>1;
	la[x]=max(la[x],l),ra[x]=min(ra[x],r);
	gr else{if(!mp2.count(x))continue;
	x=mp2[x];//mp2_[x]++;
	int l=(mp2_[x]-d+1)>>1,r=(mp2_[x]+d)>>1;
	//printf("? %d %d %d %d %d\n",x,mp2_[x],d,l,r);
	lb[x]=max(lb[x],l),rb[x]=min(rb[x],r);gr gr
//	rg(n)odb(la[i]),odb(ra[i]);odp(lb[i],rb[i]);gr
	rg(n)add(S,i,la[i],ra[i],1),add(i+n,T,lb[i],rb[i],1);if(la[i]>ra[i]||lb[i]>rb[i])return puts("-1")&0;gr
//	if(op==1)x=mp1[x],x?add(S,x,(mp1_[R[i]]-d+1)>>1,(mp1_[R[i]]+d)>>1,1):(void)x;
//	else x=mp2[x],x?add(x+n,T,(mp2_[C[i]]-d+1)>>1,(mp2_[C[i]]+d)>>1,1):(void)x;gr

	rg(n)f[i]=cnt,pig(mp1[R[i]],mp2[C[i]]+n,1,1);gr
	rebuild();int flow=0;
//	return 0;
	while(bfs(s,t))flow+=dfs(s,t,0x3f3f3f3f);
	if(qwq!=flow)return puts("-1")&0;
	flow=0;
	while(bfs(S,T))flow+=dfs(S,T,0x3f3f3f3f);
	oldl(r*n-(r-b)*flow);
	rg(n)putchar((ff^!!e[f[i]].w)?'r':'b');gr
	//rg_(u,n)for(int i=h[mp1[R[u]]];i;i=e[i].nxt)if(e[i].v==mp2[C[u]]+n){putchar((ff^e[i].w)?'r':'b');break;gr gr
}