#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
map<int,int> mp;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mp.clear();
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int x; scanf("%d",&x);
			mp[x]++; cnt=max(cnt,mp[x]);
		}
		int ans=0;
		while(cnt!=n)
		{
			ans++;
			int need=min(cnt,n-cnt);
			cnt+=need; ans+=need;
		}
		printf("%d\n",ans);
	}
	return 0;
}