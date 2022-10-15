#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],c[MAXN],d[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ll sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&c[i]);
			sum+=c[i];
		}
		sum/=n;
		for(int i=1;i<=n+1;i++) d[i]=0;
		int cnt=sum;
		for(int i=n;i>=1;i--)
		{
			d[i]+=d[i+1];
			c[i]-=d[i];
			if(c[i]==i) 
			{
				a[i]=1;
				d[i-1]++; d[i-cnt]--; 
				cnt--;
			}
			else
			{
				a[i]=0;
				d[i-1]++; d[i-cnt]--; 
			}
		}
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}