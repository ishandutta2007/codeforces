#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=300005;
int n,m,cnt[N],ans[N],p[N],a[N];
bool vis[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x)
{
	rep(i,1,n)
	{
		int y=i-x;
		if(y>=1) p[y]=a[i];
		else p[y+n]=a[i];
	}
	int cir=0;
	rep(i,1,n) vis[i]=0;
	rep(i,1,n) if(!vis[i])
	{
		++cir;
		for(int x=i; !vis[x]; x=p[x]) vis[x]=1;
	}
	if(n-cir<=m) return 1;
	return 0;
}

void solve()
{
	n=getint(),m=getint(),*ans=0;
	rep(i,1,n) a[i]=getint();
	rep(i,0,n-1) cnt[i]=0;
	rep(i,1,n) if(a[i]<=i) ++cnt[i-a[i]]; else ++cnt[n-a[i]+i];
	rep(i,0,n-1) if(cnt[i]>=n-2*m && check(i)) ans[++*ans]=i;
	printf("%d",ans[0]);
	rep(i,1,*ans) printf(" %d",ans[i]);
	puts("");
} 

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}