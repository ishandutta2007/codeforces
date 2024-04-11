#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m,a[MAXN],dp[MAXN],ans[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[l-1]++;
		a[r]--;
	}
	for(int i=1;i<m;i++)
		a[i]+=a[i-1];
	memset(ans,0,sizeof(ans));
	fill(dp,dp+m,INF);
	for(int i=0;i<m;i++)
	{
		ans[i]+=upper_bound(dp,dp+m,a[i])-dp+1;
		*upper_bound(dp,dp+m,a[i])=a[i];
	}
	for(int i=0;i<m/2;i++)
		swap(a[i],a[m-1-i]);
	fill(dp,dp+m,INF);
	for(int i=0;i<m;i++)
	{
		ans[m-1-i]+=upper_bound(dp,dp+m,a[i])-dp+1;
		*upper_bound(dp,dp+m,a[i])=a[i];
	}
	int res=0;
	for(int i=0;i<m;i++)
		res=max(res,ans[i]-1);
	printf("%d\n",res);
	return 0;
}