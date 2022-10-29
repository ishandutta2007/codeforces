#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005;
int n,X[N],Y[N],a[N],b[N];
LL ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

LL calc(LL n)
{
	return n*(n-1)*(n-2)/6;
}

void solve()
{
	n=getint();
	rep(i,1,n) X[i]=Y[i]=0;
	rep(i,1,n)
	{
		a[i]=getint(),b[i]=getint();
		++X[a[i]],++Y[b[i]];
	}
	ans=calc(n);
	rep(i,1,n)
		ans-=(LL)(X[a[i]]-1)*(Y[b[i]]-1);
	printf("%lld\n",ans);
}

int main()
{
//	freopen("c.in","r",stdin);
	int T=getint();
	while(T--)
		solve();
	return 0;
}