#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> r[MAXN],c[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			r[x].push_back(i);
			c[x].push_back(j);
		}
	ll sum=0;
	for(int i=1;i<=100000;i++)
	{
		sort(r[i].begin(),r[i].end());
		ll s=0;
		int cnt=0;
		for(auto x:r[i])
		{
			sum+=(1LL*cnt*x-s);
			cnt++; s+=x;
		}
		sort(c[i].begin(),c[i].end());
		s=0; cnt=0;
		for(auto x:c[i])
		{
			sum+=(1LL*cnt*x-s);
			cnt++; s+=x;
		}
	}
	printf("%lld\n",sum);
	return 0;
}