#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,t;
ll d,a[10];
set<ll> ss;
bool solve(ll x)
{
	ll comb=(1<<x)-1;
	while(comb<1<<d)
	{
		ll s=0;
		bool f=true;
		for(ll i=0;i<d;i++)
		{
			if((comb>>i)&1) 
			{
				if(s==0&&a[i]==0) {f=false; break;}
				s=s*10+a[i];
			}
		}
		if(ss.count(s)&&f) return true;
		ll x=comb&-comb,y=comb+x;
		comb=((comb&~y)/x>>1)|y;
	}
	return false;
}
int main()
{
	for(ll i=1;i*i<=2000000000;i++)
		ss.insert(i*i);
	scanf("%I64d",&n);
	t=n;d=0;
	while(t) {a[d++]=t%10; t=t/10;}
	for(ll i=0;i<d/2;i++)
		swap(a[i],a[d-1-i]);
	for(ll i=d;i>=1;i--)
	{
		if(solve(i)) 
		{
			printf("%I64d\n",d-i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}