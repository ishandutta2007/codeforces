#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=400005;
int n,a[N];
LL ans;

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
	n=getint(),ans=a[0]=a[n+1]=0;
	rep(i,1,n) a[i]=getint();
	rep(i,1,n)
	{
		int x=min(a[i],max(a[i-1],a[i+1]));
		ans+=a[i]-x,a[i]=x;
	}
	rep(i,1,n) ans+=a[i]-min(a[i],a[i-1])+a[i]-min(a[i],a[i+1]);
	printf("%lld\n",ans);
	
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}