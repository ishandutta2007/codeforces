#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005;
int n,k,a[N];
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
	n=getint(),k=getint();
	int mn=300000,mx=0;
	ans=0;
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) mn=min(mn,a[i]),mx=max(mx,a[i]);
	rep(i,1,n-1) ans+=abs(a[i]-a[i+1]);
	int x=mn-1;
	if(x>0)
	{
		ans+=x-1;
		ans+=min(min(abs(x-a[1]),abs(x-a[n])),mn-x+mn-1);
	}
	x=mx+1;
	if(x<=k)
	{
		ans+=k-x;
		ans+=min(min(abs(x-a[1]),abs(x-a[n])),x-mx+k-mx);
	}
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}