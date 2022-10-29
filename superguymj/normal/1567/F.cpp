#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int hx[]={0,0,-1,1};
const int hy[]={1,-1,0,0};
const int N=505;
int n,m,ans[N*N],cnt,h[N*N],id[N][N],tot,p[10];
char s[N][N];
struct edge{int v,n;} e[N*N*10];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void dfs(int x,int tp)
{
	if(ans[x]) return;
	ans[x]=tp;
	if(ans[x]<0) ans[x]+=5;
	for(int i=h[x]; i!=-1; i=e[i].n)
		dfs(e[i].v,-tp);
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) id[i][j]=++tot;
	memset(h,-1,sizeof(h));
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='X')
	{
		int t=0;
		rep(k,0,3)
		{
			int x=i+hx[k];
			int y=j+hy[k];
			if(s[x][y]=='.') p[++t]=id[x][y];
		}
		if(t&1) return puts("NO"),0;
		rep(k,1,t>>1) addedge(p[k],p[t-k+1]);
	}
	rep(i,1,n)
		rep(j,1,m)
			if(s[i][j]=='.')
				dfs(id[i][j],1);
	puts("YES");
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			int tot=0;
			if(s[i][j]=='X')
			{
				rep(k,0,3)
				{
					int x=i+hx[k];
					int y=j+hy[k];
					if(s[x][y]=='.') tot+=ans[id[x][y]]; 
				}
				printf("%d ",tot);
			}
			else printf("%d ",ans[id[i][j]]);
		}
		puts("");
	}	
	return 0;
}