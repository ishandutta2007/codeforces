#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=355;
int n,a[N],ans[N][N];

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(j,1,n)
	{
		rep(i,2,n) ans[i][j]=(ans[i-1][j]+j)%n;
	}
	rep(j,1,n)
	{
		int x=(a[j]-ans[j][j]+n)%n;
		rep(i,1,n) ans[i][j]=(ans[i][j]+x)%n;
	}
	rep(i,1,n)
	{
		rep(j,1,n) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}