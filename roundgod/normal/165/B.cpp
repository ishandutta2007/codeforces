#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
bool C(ll x)
{
	ll ans=0,s=1;
	while(s<=x)
	{
		ans+=x/s;
		if(ans>=n) return true;
		s=s*k;
	}
	return false;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	ll lb=0,rb=1LL*INF*10+1;
	while(rb-lb>1)
	{
		ll mid=(lb+rb)/2;
		if(C(mid)) rb=mid; else lb=mid;
	}
	printf("%I64d\n",rb);
	return 0;
}