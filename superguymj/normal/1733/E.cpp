#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=125;
LL k;
int n,m;
LL f[N][N];

LL calc(LL k,int n,int m)
{
	rep(i,0,n) rep(j,0,m) f[i][j]=0;
	f[0][0]=k;
	rep(i,0,n) rep(j,0,m) f[i][j+1]+=(f[i][j]+1)/2,f[i+1][j]+=f[i][j]/2;
	return f[n][m];
}

void solve()
{
	scanf("%lld%d%d",&k,&n,&m);
	k=k-n-m+1;
	if(k<=0)
	{
		puts("NO");
		return;
	}
	if(calc(k,n,m)!=calc(k-1,n,m))
		puts("YES");
	else puts("NO");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}