#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int hx[]={0,0,-1,1};
const int hy[]={-1,1,0,0};
int n,m,len,sx,sy,tx,ty,ans,a[10];
bool vis[10];
char s[100][100],t[200];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check()
{
	int x=sx,y=sy;
	rep(i,1,len)
	{
		x+=hx[a[t[i]-48]];
		y+=hy[a[t[i]-48]];
		if(!x || !y || x>n || y>m || s[x][y]=='#') return 0;
		if(x==tx && y==ty) return 1;
	}
	return 0;
}

void dfs(int x)
{
	if(x>3)
	{
		ans+=check();
		return;
	}
	rep(i,0,3)
		if(!vis[i])
			a[x]=i,vis[i]=1,dfs(x+1),vis[i]=0,a[x]=0;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n)
		rep(j,1,m)
		{
			if(s[i][j]=='S') sx=i,sy=j;
			if(s[i][j]=='E') tx=i,ty=j;
		}
	scanf("%s",t+1),len=strlen(t+1);
	dfs(0),printf("%d\n",ans);
}