#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=105;
int n,k,a[N],mx[N];
LL ans;

void solve()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,0,k-1) mx[i]=0;
	rep(i,1,n) mx[i%k]=max(mx[i%k],a[i]);
	ans=0;
	rep(i,0,k-1) ans+=mx[i];
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}