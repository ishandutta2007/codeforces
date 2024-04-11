#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,m;

void solve()
{
	scanf("%d%d",&n,&m);
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
	}
	if(n>m) puts("YES");
	else puts("NO");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}