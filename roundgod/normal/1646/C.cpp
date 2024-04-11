#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		vector<ll> fact;
		ll s=6;
		int now=3;
		while(s<=n)
		{
			fact.push_back(s);
			now++;
			s*=now;
		}
		int sz=(int)fact.size();
		int ans=INF;
		for(int i=0;i<(1<<sz);i++)
		{
			ll sum=0;
			for(int j=0;j<sz;j++)
				if(i&(1<<j)) sum+=fact[j];
			if(sum<=n) ans=min(ans,__builtin_popcount(i)+__builtin_popcountll(n-sum));
		}
		printf("%d\n",ans);
	}
}