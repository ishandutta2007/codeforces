#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+50;
ll n,m,S=0,now;
ll p[N];
int main()
{
	ios::sync_with_stdio(false);
	ll i,d,pos;
	cin>>n>>m;
	for(i=1;i<=m;i++) 
	{
		cin>>p[i],S+=p[i];
		if(p[i]>n-i+1)
		{
			puts("-1");
			return 0;
		}
	}
	if(S<n)
	{
		puts("-1");
		return 0;
	}
	S-=n;
	printf("%lld ",n-p[1]+1);
	pos=n-p[1]+1;
	for(i=2;i<=m;i++)
	{
		if(S>0)
		{
			d=min(S,p[i-1]-1);
			S-=d;
			pos=n-(i-2)-p[i-1]+d-p[i]+1;
			printf("%lld ",pos);
		}
		else
		{
			pos-=p[i];
			printf("%lld ",pos);
		}
	}
	return 0;
}