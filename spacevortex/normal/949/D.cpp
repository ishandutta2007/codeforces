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
const ll N=2e5+50;
ll n,m,D,B,ans=0;
ll a[N],s[N];
int main()
{
	ll i,p,now,val;
	n=rd();D=rd();B=rd();
	m=(n+1)>>1;
	for(i=1;i<=n;i++)
	{
		a[i]=rd();
		s[i]=s[i-1]+a[i];
	}
	now=val=0;
	for(i=1;i<=m;i++)
	{
		p=min(i*(D+1),n);
		if(s[p]-now>=B) val++,now+=B;
	}
	ans=max(ans,m-val);
	now=val=0;
	for(i=n;i>m;i--)
	{
		p=max(n-(n-i+1)*(D+1)+1,1ll);
		if(n*B-s[p-1]-now>=B) val++,now+=B;
	}
	ans=max(ans,n-m-val);
	printf("%I64d",ans);
	return 0;
}