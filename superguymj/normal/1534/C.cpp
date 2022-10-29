#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=400005,mod=1000000007;
bool vis[N];
int n,ans,a[N],p[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint(),ans=1;
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) p[a[i]]=getint();
	rep(i,1,n) vis[i]=0;
	rep(i,1,n) if(!vis[i])
	{
		for(int x=i; !vis[x]; x=p[x]) vis[x]=1;
		ans=ans*2%mod;
	}
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}