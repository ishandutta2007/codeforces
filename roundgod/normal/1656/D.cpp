#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
ll n;
bool check(ll x)
{
	if(x<=1) return false;
	if(x>=INF) return false;
	if(1LL*x*(x+1)/2>n) return false;
	if((x&1)&&(n%x)) return false;
	if((x%2==0)&&(n%x!=x/2)) return false;
	return true;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll x=2;
		bool f=false;
		while(x<=n)
		{
			if(check(x)) {printf("%lld\n",x); f=true; break;}
			if(n%x==0&&((n/x)&1)&&check(n/x))
			{
				printf("%lld\n",n/x);
				f=true;
				break;
			}
			x=x*2;
		}
		if(!f) puts("-1");
	}
	return 0;
}