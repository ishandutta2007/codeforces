#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k1,k2,a[MAXN],b[MAXN];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d%d%d",&n,&k1,&k2);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		a[i]=max(a[i]-b[i],b[i]-a[i]);
	}
	priority_queue<int> pq;
	for(int i=0;i<n;i++) pq.push(a[i]);
	int tt=k1+k2;
	while(tt>0)
	{
		int p=pq.top();
		pq.pop();
		if(p==0) 
		{
			printf("%d\n",tt&1);
			return 0;
		}
		pq.push(p-1);
		tt--;
	}
	ll ans=0;
	while(pq.size())
	{
		ans+=(ll)pq.top()*pq.top();
		pq.pop();
	}
	printf("%I64d\n",ans);
	return 0;
}