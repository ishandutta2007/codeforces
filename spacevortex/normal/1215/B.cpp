#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=4e5+20;
ll n,ans=0;
ll cnt[2];
int main()
{
	ll i,x;
	n=rd();
	for(i=1;i<=n;i++)
	{
		x=rd();
		if(x>0) x=1;
		else x=0;
		ans+=cnt[x];
		if(x==0) swap(cnt[0],cnt[1]);
		else ans++;
		cnt[x]++;
	}
	printf("%I64d %I64d",(n*(n+1)/2ll)-ans,ans);
	return 0;
}