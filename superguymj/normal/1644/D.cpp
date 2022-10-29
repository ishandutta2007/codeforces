#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005,mod=998244353;
typedef long long LL;
int t,n,m,k,q,X[N],Y[N];
LL ans;
struct D{int x,y;} dat[N];

void solve(int p)
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	rep(i,1,q) scanf("%d%d",&dat[i].x,&dat[i].y);
	ans=1;
	bool full=0;
	int x=0,y=0;
	repd(i,q,1)
	{
		if(!full && (X[dat[i].x]!=p || Y[dat[i].y]!=p)) ans=ans*k%mod;
		if(X[dat[i].x]!=p) ++x;
		if(Y[dat[i].y]!=p) ++y;
		X[dat[i].x]=Y[dat[i].y]=p;
		if(x==n || y==m) full=1;
	}
	printf("%lld\n",ans);
}

int main()
{
	scanf("%d",&t);
	rep(i,1,t) solve(i);
	return 0;
}