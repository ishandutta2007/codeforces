#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
int n,x,y;

void solve()
{
	scanf("%d%d%d",&n,&x,&y);
	if(x<y) swap(x,y);
	if(y!=0)
	{
		puts("-1");
		return;
	}
	if(x==0)
	{
		puts("-1");
		return;
	}
	if((n-1)%x)
	{
		puts("-1");
		return;
	}
	int nw=1;
	rep(i,1,n-1)
	{
		if(i!=1 && (i-1)%x==0) nw=i+1;
		printf("%d ",nw);
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}