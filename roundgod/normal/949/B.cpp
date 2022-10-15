#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,q;
ll solve(ll x,ll y,int type)
{
	if(type==1) 
		{if(y==1) return solve(x,x,0); else return solve(x,y-1,0);}
	if(y&1) return (y+1)/2;
	else 
	{
		if(x&1) return (x+1)/2+solve(x/2,y/2,1);
		else return x/2+solve(x/2,y/2,0);
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&q);
	for(ll i=0;i<q;i++)
	{
		ll x;
		scanf("%I64d",&x);
		printf("%I64d\n",solve(n,x,0));
	}
	return 0;
}