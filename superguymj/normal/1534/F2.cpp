#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define id(x,y) (((x)-1)*m+(y))

using namespace std;
const int N=400005;
bool mp[N];
char s[N];
int n,m,a[2][N],f[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void dfs(int x,int y,int t,int tp)
{
	if(a[tp][id(x,y)]) return;
	a[tp][id(x,y)]=t;
	if(x+1<=n) dfs(x+1,y,t,tp);
	if(y-1>0 && mp[id(x,y-1)]) dfs(x,y-1,t,tp);
	if(y+1<=m && mp[id(x,y+1)]) dfs(x,y+1,t,tp);
	if(x-1>0 && mp[id(x-1,y)]) dfs(x-1,y,t,tp);
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n)
	{
		scanf("%s",s+1);
		rep(j,1,m)
		{
			char c=s[j];
			if(c=='#') mp[id(i,j)]=1;
		}
	}
	rep(i,1,m) rep(j,1,n) if(mp[id(j,i)]) dfs(j,i,i,0);
	repd(i,m,1) rep(j,1,n) if(mp[id(j,i)]) dfs(j,i,i,1);
	rep(i,0,m+1) f[i]=m+2;
	rep(i,1,m)
	{
		int x=getint();
		if(!x) continue;
		repd(j,n,1) if(mp[id(j,i)])
		{
			if(!(--x))
			{
				int l=a[0][id(j,i)];
				int r=a[1][id(j,i)];
				f[l]=min(f[l],r+1);
				break;
			}
		}
	}
	repd(i,m,1) f[i]=min(f[i],f[i+1]);
	int x=1;
	while(x<=m+1) x=f[x],++ans;
	printf("%d\n",ans-1);
	return 0;
}