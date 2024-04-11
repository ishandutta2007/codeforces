#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int K=30;
int tot;

int query(int x)
{
	printf("? %d %d\n",tot,tot+x);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

void solve()
{
	tot=1;
	rep(i,1,K)
	{
		int x=query(1<<i);
		if(x!=(1<<i)) tot+=(1<<i-1);
	}
	printf("! %d\n",(1<<K)-tot);
	fflush(stdout);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}