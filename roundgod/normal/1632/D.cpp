#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dp[MAXN];
vector<P> v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		for(auto &p:v) p.F=__gcd(a[i],p.F);
		v.push_back(P(a[i],i));
		vector<P> tmp;
		for(auto p:v)
		{
			if(tmp.size()&&tmp.back().F==p.F) tmp.pop_back();
			tmp.push_back(p);
		}
		swap(v,tmp);
		int pre=0,ans=-1;
		for(int j=0;j<(int)v.size();j++)
		{
			int l=i-v[j].S+1,r=i-pre;
			if(v[j].F>=l&&v[j].F<=r) {ans=v[j].F; break;}
			pre=v[j].S;
		}
		if(ans==-1) dp[i]=dp[i-1]; else dp[i]=max(dp[i-1],dp[i-ans]+1);
	}
	for(int i=1;i<=n;i++) printf("%d ",dp[i]);
	puts("");
	return 0;
}