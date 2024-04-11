#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=7005;
bool vis[2][N];
int n,t[2][N],f[2][N],x,win[2][N];
int head,tail;
struct data{bool tp; int x;} q[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void bfs()
{
	while(head<=tail)
	{
		bool tp=q[head].tp;
		int x=q[head++].x;
		if(f[tp][x]==-1)
		{
			rep(i,1,t[tp^1][0])
			{
				int v=(x-t[tp^1][i]+n)%n;
				if(!vis[tp^1][v])
				{
					f[tp^1][v]=1;
					vis[tp^1][v]=1;
					q[++tail]=(data){tp^1,v};
				}
			}
		}
		else
		{
			rep(i,1,t[tp^1][0])
			{
				int v=(x-t[tp^1][i]+n)%n;
				++win[tp^1][v];
				if(win[tp^1][v]==t[tp^1][0])
				{
					f[tp^1][v]=-1;
					vis[tp^1][v]=1;
					q[++tail]=(data){tp^1,v};
				}
			}
		}
	}
}

int main()
{
	n=getint();
	t[0][0]=getint();
	rep(i,1,t[0][0]) t[0][i]=getint();
	t[1][0]=getint();
	rep(i,1,t[1][0]) t[1][i]=getint();
	
	vis[0][0]=vis[1][0]=1;
	f[0][0]=f[1][0]=-1;
	q[head=0]=(data){0,0};
	q[tail=1]=(data){1,0};
	bfs();
	
	rep(i,1,n-1)
	{
		x=f[0][i];
		if(x==-1) printf("Lose ");
		if(x==1) printf("Win ");
		if(x==0) printf("Loop ");
	}
	puts("");
	rep(i,1,n-1)
	{
		x=f[1][i];
		if(x==-1) printf("Lose ");
		if(x==1) printf("Win ");
		if(x==0) printf("Loop ");
	}
	puts("");
	return 0;
}