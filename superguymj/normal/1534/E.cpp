#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=505;
bool vis[N][N],loop[N],inq[N],cnt[N];
int n,m,p[N],q[N],head,tail,dis[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void bfs(int x)
{
	q[head=tail=0]=0,inq[0]=1;
	while(head<=tail)
	{
		int x=q[head++];
		rep(i,0,x) if(n-x>=m-i && i<=m)
		{
			int y=x+m-2*i;
			vis[x][y]=1;
			if(!inq[y]) q[++tail]=y,inq[y]=1,dis[y]=dis[x]+1;
		}
	}
}

void dfs1(int x)
{
	loop[x]=1;
	rep(i,0,n) if(vis[i][x] && dis[i]+1==dis[x] && !loop[i]) dfs1(i);
}

int query()
{
	printf("?");
	rep(i,1,m) printf(" %d",p[i]);
	puts(""),fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

void dfs2(int x)
{
	rep(i,0,n) if(loop[i] && vis[x][i] && dis[x]+1==dis[i])
	{
		int a=(x+m-i)>>1;
		int b=m-a,tot=0;
		rep(j,1,n)
			if(cnt[j]) {if(a) --a,p[++tot]=j,cnt[j]^=1;}
			else {if(b) --b,p[++tot]=j,cnt[j]^=1;}
		ans^=query();
		dfs2(i);
		return;
	}
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) dis[i]=n*m+1;
	bfs(0);
	if(dis[n]>n*m) return puts("-1"),0;
	dfs1(n);
	dfs2(0);
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}