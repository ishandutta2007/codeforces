#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=5005,INF=1000000000;
int t,x,n,a[5005],mx[5005],ans;

void solve()
{
	scanf("%d%d",&n,&x);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) mx[i]=-INF;
	rep(i,1,n)
	{
		int tmp=0;
		rep(j,i,n) mx[j-i+1]=max(mx[j-i+1],(tmp+=a[j]));
	}
	rep(i,0,n)
	{
		ans=0;
		rep(j,0,n) ans=max(ans,mx[j]);
		printf("%d ",ans);
		rep(j,i+1,n) mx[j]+=x;
	}
	puts("");
}

int main()
{
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}