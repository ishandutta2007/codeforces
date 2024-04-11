#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int last[MAXN],cnt[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		last[i]=-1;
		if(a[i]==0) continue;
		for(int j=i-1;j>=0;j--)
			if(1LL*a[i]*a[j]>=0&&a[j]!=0)
			{
				ll res=sqrt(1LL*a[i]*a[j]);
				if(res*res==1LL*a[i]*a[j]) {last[i]=j; break;}
			}
		//printf("%d\n",last[i]);
	}
	for(int i=0;i<n;i++)
	{
		int s=a[i]==0?0:1; cnt[1]++;
		for(int j=i+1;j<n;j++)
		{
			if(last[j]<i&&a[j]!=0) s++;
			cnt[max(s,1)]++;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",cnt[i]);
	return 0;
}