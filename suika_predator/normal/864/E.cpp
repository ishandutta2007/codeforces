#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
struct atom
{
	int t,d,p,id;
	inline bool operator<(const atom &a)const{return d<a.d;}
}a[111];
int dp[111][2017];
vector<int> pick[111][2017];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].d;j++)
		{
			dp[i][j]=dp[i-1][j];
			pick[i][j]=pick[i-1][j];
			if(j>=a[i].t&&dp[i][j]<dp[i-1][j-a[i].t]+a[i].p)
			{
				dp[i][j]=dp[i-1][j-a[i].t]+a[i].p;
				pick[i][j]=pick[i-1][j-a[i].t];
				pick[i][j].push_back(i);
			}
		}
	}
	int maxx=0;
	vector<int> res;
	for(int j=0;j<=2000;j++)
	{
		if(dp[n][j]>maxx)
		{
			maxx=dp[n][j];
			res=pick[n][j];
		}
	}
	printf("%d\n%d\n",maxx,res.size());
	for(auto x:res)printf("%d ",a[x].id);
	printf("\n");
	return 0;
}