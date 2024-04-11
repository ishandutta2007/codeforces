#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int n;
int dp[N],f[N][2],fa[N],p[3];
bool cmp(const int &a,const int &b)
{
	return dp[a]>dp[b];
}
void solve(int x)
{
	int y,val;
	dp[x]=1;
	while(x>1)
	{
		y=x;x=fa[x];
		p[0]=f[x][0];p[1]=f[x][1];p[2]=y;
		sort(p,p+3,cmp);
		unique(p,p+3);
		f[x][0]=p[0];
		f[x][1]=p[1];
		if(x==1) val=max(dp[f[x][0]],dp[f[x][1]]);
		else val=max(dp[f[x][0]],dp[f[x][1]]+1);
		if(val==dp[x]) break;
		dp[x]=val;
	}
}
int main()
{
	int i;
	scanf("%d",&n);n++;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		solve(i);
		printf("%d ",dp[1]);
	}
	return 0;
}