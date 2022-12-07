#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
const ll P=140;
ll n,p,Q,ans=0;
ll p1[P],p2[P],f[P];
ll C(ll a,ll b)
{
	ll i,j,d,ret=1;
	for(i=1;i<=b;i++) p1[i]=a-i+1;
	for(i=1;i<=b;i++) p2[i]=i;
	for(i=1;i<=b;i++)
	{
		for(j=1;j<=b;j++)
		{
			d=__gcd(p1[i],p2[j]);
			p1[i]/=d;p2[j]/=d;
		}
	}
	for(i=1;i<=b;i++) ret*=p1[i];
	return ret;
}
int main()
{
	ll i,q,nas,w;
	cin>>n>>p>>Q;
	p=min(n-1,p);
	for(i=0;i<=p;i++) f[i]=C(n,i);
	for(q=1;q<=Q;q++)
	{
		nas=0;
		for(i=0,w=1;i<=p;i++,w*=q) nas+=f[i]*w;
		ans^=q*nas;
	}
	cout<<ans;
	return 0;
}