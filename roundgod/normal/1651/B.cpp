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
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<ll> v;
		ll now=1;
		for(int i=1;i<=n;i++)
		{
			v.push_back(now);
			if(now>INF) break;
			now=3*now;
		}
		if(v.back()>INF) puts("NO");
		else 
		{
			puts("YES");
			for(auto x:v) printf("%lld ",x);
			puts("");
		}
	}
	return 0;
}