#include<bits/stdc++.h>
using namespace std;
struct P{
	long long x,y;
};
long long QQ(P a, P b)
{
	if (a.y==b.y) return 0;
	long long c = a.x*b.y-a.y*b.x;
	if (c%(b.y-a.y)!=0) return 0;
	return c/(b.y-a.y);
}
P s[300];
int a[1010000];
int ans[1010000];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		s[i]=(P){x,y};
	}
	for(int i = 0;i<m;i++)
	{
		memset(a,0,sizeof(a));
		for(int j = i+1;j<m;j++)
		{
			long long c = QQ(s[i],s[j]);
			if (c<=0) continue;
			if (c>n) continue;
			else a[c]++;
		}
		for(int j = 1;j<=n;j++)
		{
			ans[j]=max(ans[j],a[j]);
		}
	}
	int an = n;
	for(int i = 1;i<=n;i++) an += ans[i];
	printf("%d\n",an);
	return 0;
}