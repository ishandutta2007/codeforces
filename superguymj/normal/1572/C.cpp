#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=3005;
int T,n,x,a[N],c[N],lst[N],f[N][N];

void solve()
{
	scanf("%d",&n);
	rep(i,1,n) c[i]=0;
	rep(i,1,n) scanf("%d",&x),lst[i]=c[x],c[x]=i;
	rep(r,1,n) repd(l,r-1,1)
	{
		f[l][r]=f[l][r-1]+1;
		for(int i=lst[r]; i>=l; i=lst[i])
			f[l][r]=min(f[l][r],f[l][i]+f[i+1][r]);
	}
	printf("%d\n",f[1][n]);
}

int main()
{
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}