#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int inf=1000000000;
int num[3000010];
long long sum[3000010];
int main()
{
	int n;
	long long x,y;
	cin>>n>>x>>y;
	long long ans=inf*1ll*inf,nans;
	for(int i=1;i<=n;i++)
	{
		int t1;
		scanf("%d",&t1);
		num[t1]++;
		sum[t1]+=t1;
	}
	for(int i=1;i<=2000000;i++)
	{
		num[i]+=num[i-1];
		sum[i]+=sum[i-1];
	}
	int k=x/y;
	for(int i=2;i<=1000000;i++)
	{
		nans=0;
		if(i-1>k)
			for(int j=0;j<=1000000;j+=i)
				nans+=y*((num[j+i-1]-num[j+i-1-k])*1ll*(j+i)-(sum[j+i-1]-sum[j+i-1-k]))+x*(num[j+i-1-k]-num[j]);
		else
			for(int j=0;j<=1000000;j+=i)
				nans+=y*((num[j+i-1]-num[j])*1ll*(j+i)-(sum[j+i-1]-sum[j]));		
		ans=min(ans,nans);
	}
	cout<<ans;
}