#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,H;
ll find_min(ll x)
{
	return (H+x)*(x-H+1)/2+x*(x-1)/2;
}
ll cnt_num(ll x,ll rest)
{
	if(x*(x+1)/2>=rest) return x;
	return (rest-x*(x+1)/2-1)/x+1+x;
}
int main()
{
	while(scanf("%I64d%I64d",&n,&H)==2)
	{
		if(H>2LL*INF||H*(H+1)/2>n)
		{
			ll lb=1,rb=min(2LL*INF,H);
			while(rb-lb>1)
			{
				ll mid=(lb+rb)/2;
				if(mid*(mid+1)/2<=n) lb=mid; else rb=mid;
			}
			printf("%I64d\n",cnt_num(lb,n));
			continue;
		}
		ll lb=H,rb=2LL*INF;
		while(rb-lb>1)
		{
			ll mid=(lb+rb)/2;
			if(find_min(mid)<=n) lb=mid; else rb=mid;
		}
		ll rest=n-(H+lb-1)*(lb-H)/2;
		printf("%I64d\n",lb-H+cnt_num(lb,rest));
	}
	return 0;
}