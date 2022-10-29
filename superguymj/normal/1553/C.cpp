#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100;
char s[N];
int n,a[N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int calc()
{
	int x=5,y=5,sx=0,sy=0;
	rep(i,1,10)
	{
		if(i&1)
		{
			--x;
			if(a[i]) ++sx;
		}
		else
		{
			--y;
			if(a[i]) ++sy;
		}
		if(sx+x<sy) return i;
		if(sy+y<sx) return i;
	}
	return 10;
}

void dfs(int x)
{
	if(x>10)
	{
		ans=min(ans,calc());
		return;
	}
	if(a[x]>-1) dfs(x+1);
	else
		a[x]=1,dfs(x+1),a[x]=0,dfs(x+1),a[x]=-1;
}

void solve()
{
	scanf("%s",s+1);
	rep(i,1,10)
	{
		if(s[i]=='1') a[i]=1;
		if(s[i]=='0') a[i]=0;
		if(s[i]=='?') a[i]=-1;
	}
	ans=10,dfs(1);
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
}