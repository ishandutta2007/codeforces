#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
const int N=205,M=2005;
int n,m,l,x,y,z,T,L,ans;
int son[N],f[N],d[N],ed[M],next[M],data[M],tmp[M],v[N],b[N],c[N][N];
bool build(int S)
{
	int h=0,t=1; f[1]=S; rep(i,n) d[i]=-1; d[S]=0;
	while (h<t){
		int x=f[++h];
		for (int p=son[x];p;p=next[p]) if (data[p]){
			int y=ed[p];
			if (d[y]<0) d[y]=d[x]+1,f[++t]=y;
			if (y==T) return 1;
			}
		}
	return 0;
}
int dinic(int x,int low)
{
	if (x==T) return low; int w=0,res;
	for (int p=son[x];p && w<low;p=next[p]) if (data[p]){
		int y=ed[p];
		if (d[y]==d[x]+1 && (res=dinic(y,min(low-w,data[p]))))
			data[p]-=res,data[p^1]+=res,w+=res;
		}
	if (!w) d[x]=-1; return w;
}
void pre(int rest,int dep)
{
	int S,flow=0,o[N]; rep(i,n) if (b[i]==dep) S=T,T=i;
	if (rest==1){b[T]=1<<20; return;}
	
	memcpy(data,tmp,sizeof(data));
	while (build(S)) flow+=dinic(S,1<<20);
	rep(i,n) rep(j,n) if ((d[i]<0)!=(d[j]<0)) c[i][j]=min(c[i][j],flow);
	rep(i,n) o[i]=d[i]<0;
	
	int s1=0,s2=0;
	rep(i,n) if (b[i]==dep && !o[i]) ++b[i],++s1; pre(s1,dep+1);
	rep(i,n) if (b[i]==dep && o[i]) ++b[i],++s2; pre(s2,dep+1);
}
void dfs(int rest,int dep)
{
	rep(i,n) if (b[i]==dep) T=i;
	if (rest==1){v[++L]=T; b[T]=1<<20; return;}
	int S,res=1<<20,o[N];
	rep(i,n) if (b[i]==dep && i!=T) if (c[i][T]<res) res=c[i][T],S=i;
	
	memcpy(data,tmp,sizeof(data));
	while (build(S)) dinic(S,1<<20);
	rep(i,n) o[i]=d[i]<0;
	
	int s1=0,s2=0; ans+=res;
	rep(i,n) if (b[i]==dep && !o[i]) ++b[i],++s1; dfs(s1,dep+1);
	rep(i,n) if (b[i]==dep && o[i]) ++b[i],++s2; dfs(s2,dep+1);
}
int main()
{
	scanf("%d%d",&n,&m),l=1,L=0;
	rep(i,m) scanf("%d%d%d",&x,&y,&z),
		ed[++l]=y,data[l]=z,next[l]=son[x],son[x]=l,
		ed[++l]=x,data[l]=z,next[l]=son[y],son[y]=l;
	memcpy(tmp,data,sizeof(tmp)),memset(c,6,sizeof(c));
	pre(n,0),memset(b,0,sizeof(b)),dfs(n,0); printf("%d\n",ans);
	rep(i,n) printf("%d%s",v[i],i<n?" ":"\n");
	return 0;
}