#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int n,a[N],T;

void solve()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	if(a[n]-a[1]+1-n>2) puts("NO");
	else puts("YES");
}

int main()
{
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}