#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int cnt[MAXN],sum[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int want=(n-k+1)/2+k;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+cnt[i];
		int l=1,r=n;
		for(int i=1;i<=n;i++)
		{
			int need=sum[i-1]+want;
			if(need>n) break;
			int pos=lower_bound(sum+1,sum+n+1,need)-sum;
			if(pos-i+1<r-l+1)
			{
				l=i; r=pos;
			}
		}
		printf("%d %d\n",l,r);
		int now=1;
		for(int i=1;i<=k-1;i++)
		{
			int sum=0,last=now;
			while(sum<=0)
			{
				if(a[now]>=l&&a[now]<=r) sum++; else sum--;
				now++;
			}
			printf("%d %d\n",last,now-1);
		}
		printf("%d %d\n",now,n);
	}
	return 0;
}