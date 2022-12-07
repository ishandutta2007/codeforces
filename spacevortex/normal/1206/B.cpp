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
ll n,ans=0,w=0,cnt=0;
int main()
{
	ll i,x;
	n=rd();
	for(i=1;i<=n;i++)
	{
		x=rd();
		if(x==0) w++;
		if(x>0) ans+=x-1;
		if(x<0) ans+=-1-x,cnt++;
	}
	if(w>0) ans+=w;
	else if(cnt&1ll) ans+=2;
	printf("%I64d",ans);
	return 0;
}