#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> v;
multiset<ll> ms;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll sum=0;
		ms.clear(); v.clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			v.push_back(x);
			sum+=x;
		}
		sort(v.begin(),v.end());
		ms.insert(sum);
		int cnt=0;
		while(ms.size())
		{
			while(ms.size()&&v.back()==(*(--ms.end())))
			{
				ms.erase(--ms.end());
				v.pop_back();
			}
			if(cnt==n-1) break;
			ll x=(*(--ms.end()));
			if(x<v.back()) break;
			ms.erase(--ms.end());
			ms.insert(x/2); ms.insert((x+1)/2);
			cnt++;
		}
		if(ms.size()) puts("NO"); else puts("YES");
	}
	return 0;
}