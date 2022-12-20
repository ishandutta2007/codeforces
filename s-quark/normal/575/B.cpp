#include<cstdio>
#include<cstring>
#include<algorithm>
using  namespace std;
const int N=100005*2, P=1000000007;
int n,t,l,ans;
int g[N],d[N],u[N],v[N],pow[N*10+5];
int  ed[N],next[N],son[N];
int  fa[N][21];
bool data[N]; 
int state[N];

void addedge(int x,int y,int z)
{
	ed[++l]=y,next[l]=son[x],son[x]=l,data[l]=z;
}
void dfs(int x,int last)
{
	fa[x][0]=last;
	g[++t]=x;
	for (int p=son[x];p;p=next[p]){
		int y=ed[p];
		if (y!=last) d[y]=d[x]+1,dfs(y,x);
		state[y] = (data[p]?1:0) | (data[p^1]?2:0);
	}
}
int lca(int x,int y)
{
	if (d[x]<d[y]) swap(x,y);
	for (int j=20;j>=0;--j) if (d[fa[x][j]]>=d[y]) x=fa[x][j];
	for (int j=20;j>=0;--j) if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	return x==y?x:fa[x][0];
}
int main()
{
	int k,x,y,uni;
	scanf("%d",&n),l=1;
	pow[0]=0,pow[1]=1;
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&uni);
		addedge(x,y,1);
		addedge(y,x,!uni);
	}
	scanf("%d",&k);
	for (int i=2;i<=k+5;++i) pow[i]=pow[i-1]*2%P;
	d[1]=1;
	dfs(1,0);
	for  (int j=0;j<20;++j)
		for (int i=1;i<=n;++i)
			fa[i][j+1]=fa[fa[i][j]][j];
	/*for (int i=1;i<=n;++i){
		for  (int j=0;j<15;++j)
			printf("%d ",fa[i][j]);
		puts("");
	}*/
	x=1;
	for (int i=0;i<k;++i){
		scanf("%d",&y);
		int z=lca(x,y);
		++u[x],--u[z],++v[y],--v[z];
		//printf("%d %d %d\n",x,y,z);
		//printf("%d  %d\n",u[x],v[y]);
		x=y;
	}
	for (int i=n;i;--i){
		x=g[i];
		y=fa[x][0];
		u[y]+=u[x],v[y]+=v[x];
		//printf("%d %d  %d\n",x,u[x],v[x]);
		if  (state[x]==1)
			ans = (ans + pow[u[x]+1] - 1)%P;
		else if (state[x]==2)
			ans = (ans + pow[v[x]+1] - 1)%P;
	}
	printf("%d\n",(ans+P)%P);
	return 0;
}