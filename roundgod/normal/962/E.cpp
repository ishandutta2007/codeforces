#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,x,lastr,lastb,lastp,mr,mb,ans=0;
char ch;
int main()
{
	scanf("%I64d",&n);
	bool pp=false,bb=false,rr=false;
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d %c",&x,&ch);
		if(ch=='R'||ch=='P')
		{
			if(rr)
			{
				ans+=x-lastr;
				mr=max(mr,x-lastr);
			}
			rr=true;
			lastr=x;
		}
		if(ch=='B'||ch=='P')
		{
			if(bb)
			{
				ans+=x-lastb;
				mb=max(mb,x-lastb);
			}
			bb=true;
			lastb=x;
		}
		if(ch=='P')
		{
			if(pp)ans+=min(0LL,x-lastp-mr-mb);
			lastp=x;mr=0;mb=0;pp=true;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}