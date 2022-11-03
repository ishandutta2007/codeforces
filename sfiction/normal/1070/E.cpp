#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn=200010;
int arr[maxn];

long long gao(int n, int m, int d)
{
	long long ret = 0;

	int done = 0;
	long long done_sum = 0;

	for (int i=1;i<=n;i++)
	{
		if (arr[i]>d)
			continue;
		if (done>=m)
		{
			ret+=done_sum;
			done = 0;
			done_sum = 0;
		}
		ret += arr[i];
		done++;
		done_sum += arr[i];
	}
	return ret;
}

int calans(int n, int m, int d, long long t)
{
	int ret = 0;
	long long cost = 0;

	int done = 0;
	long long done_sum = 0;

	for (int i=1;i<=n;i++)
	{
		if (arr[i]>d)
			continue;
		if (done>=m)
		{
			cost+=done_sum;
			done = 0;
			done_sum = 0;
		}
		cost += arr[i];
		if (cost>t)
			return ret;
		ret++;
		done++;
		done_sum += arr[i];
	}
	return ret;
}

int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		int n,m;
		long long t;
		scanf("%d%d%lld",&n,&m,&t);
		for (int i=1;i<=n;i++)
			scanf("%d",&arr[i]);

		int l=1,r=maxn,mid;
		while(l<r)
		{
			mid=(l+r+1)/2;
			if (gao(n, m, mid)<=t)
				l=mid;
			else
				r=mid-1;
		}
		int d = r;
		
		int ans = calans(n, m, d, t);
		int ans1=calans(n,m,d+1, t);
		if (ans1>ans)
			ans=ans1, d++;

		if (d>t)
			d=t,ans=calans(n,m,d,t);
		printf("%d %d\n", ans, d);
	}
}