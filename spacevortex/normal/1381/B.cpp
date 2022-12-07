#include<bits/stdc++.h>
using namespace std;
const int N=4050;
int n,m;
int p[N],a[N],dp[N];
void Solve()
{
	int i,j,l,r;
	scanf("%d",&n);
	m=0;
	for(i=1;i<=(n<<1);i++) scanf("%d",&p[i]);
	p[(n<<1)+1]=1e9;
	for(l=1;l<=(n<<1);l=r)
	{
		r=l;
		while(p[r]<=p[l]) r++;
		a[++m]=r-l;
		//printf("#%d %d\n",m,a[m]);
	}
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=n;j>=a[i];j--) dp[j]|=dp[j-a[i]];
	}
	if(dp[n]) puts("YES");
	else puts("NO");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
}