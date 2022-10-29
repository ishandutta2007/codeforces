#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=805,M=2005,INF=1000000000;
char a[N],b[N];
bool vis[M][N*20];
int n,m,f[M][N*20],g[N*20][M],ans,tot;
int q[N*20],head,tail,fail[N*20],t[N*20][10];

int T(int x,int c)
{
	if(!t[x][c]) t[x][c]=++tot;
	return t[x][c];
}

void build()
{
	tot=1;
	rep(i,1,n) a[i]-=48;
	rep(i,1,m) b[i]-=48;
	if(n==m)
	{
		int x=1,y=1;
		rep(i,1,n)
		{
			if(x==y)
			{
				rep(c,a[i]+1,b[i]-1)
					++g[T(x,c)][n-i];
			}
			else
			{
				rep(c,a[i]+1,9)
					++g[T(x,c)][n-i];
				rep(c,i>1?0:1,b[i]-1)
					++g[T(y,c)][n-i];
			}
			x=T(x,a[i]);
			y=T(y,b[i]);
		}
		++g[x][0];
		if(x!=y) ++g[y][0];
	}
	else
	{
		int x=1;
		rep(i,1,n)
		{
			rep(c,a[i]+1,9)
				++g[T(x,c)][n-i];
			x=T(x,a[i]);
		}
		++g[x][0],x=1;
		rep(i,1,m)
		{
			rep(c,i>1?0:1,b[i]-1)
				++g[T(x,c)][m-i];
			x=T(x,b[i]);
		}
		++g[x][0];
		rep(i,n+1,m-1)
			rep(c,1,9)
				++g[T(1,c)][i-1];
	}
}

void acam()
{
	rep(i,0,9) t[0][i]=1;
	q[head=tail=0]=1;
	while(head<=tail)
	{
		int x=q[head++];
		rep(i,0,9) if(t[x][i])
		{
			q[++tail]=t[x][i];
			int k=fail[x];
			while(!t[k][i]) k=fail[k];
			fail[t[x][i]]=t[k][i];
		}
		rep(i,0,M-1) g[x][i]+=g[fail[x]][i];
	}
	rep(i,1,tot)
	{
		rep(j,0,9)
		{
			int x=i;
			while(!t[x][j]) x=fail[x];
			t[i][j]=t[x][j];
		}
	}
	rep(x,1,tot) rep(i,1,M-1) g[x][i]+=g[x][i-1];
}

void dp()
{
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,tot) f[i][j]=-INF;
	f[0][1]=0;
	rep(i,0,n-1)
		rep(j,1,tot) if(f[i][j]>=0)
			rep(c,0,9)
			{
				int tmp=f[i][j]+g[t[j][c]][n-i-1];
				f[i+1][t[j][c]]=max(f[i+1][t[j][c]],tmp);
			}
	ans=-INF;
	rep(i,1,tot) ans=max(ans,f[n][i]);
	rep(i,1,tot) if(ans==f[n][i]) vis[n][i]=1;
	printf("%d\n",ans);
}

void pre()
{
	repd(i,n-1,0)
		rep(j,1,tot)
			if(f[i][j]>=0)
				rep(c,0,9)
				{
					int tmp=f[i][j]+g[t[j][c]][n-i-1];
					if(f[i+1][t[j][c]]==tmp)
						vis[i][j]|=vis[i+1][t[j][c]];
				}
}

void dfs(int L,int x)
{
	if(L==n) return;
	rep(c,0,9)
	{
		if(vis[L+1][t[x][c]] && f[L+1][t[x][c]]==f[L][x]+g[t[x][c]][n-L-1])
		{
			printf("%d",c);
			dfs(L+1,t[x][c]);
			return;
		}
	}
}

int main()
{
	scanf("%s",a+1),n=strlen(a+1);
	scanf("%s",b+1),m=strlen(b+1);
	build();
	acam();
	dp();
	pre();
	dfs(0,1);
	puts("");
	return 0;
}