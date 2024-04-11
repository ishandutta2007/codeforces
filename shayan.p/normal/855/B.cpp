#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define PB push_back
int main()
{
	ll n,p,q,r;
	cin>>n>>p>>q>>r;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	ll Mins[n],Minf[n],Maxs[n],Maxf[n];
	Mins[0]=a[0];
	Maxs[0]=a[0];
	Minf[n-1]=a[n-1];
	Maxf[n-1]=a[n-1];
	for(ll i=1;i<n;i++)
	{
		Mins[i]=min(Mins[i-1],a[i]);
		Maxs[i]=max(Maxs[i-1],a[i]);
	}
	for(ll i=n-2;i>=0;i--)
	{
		Minf[i]=min(Minf[i+1],a[i]);
		Maxf[i]=max(Maxf[i+1],a[i]);
	}
	ll x=a[0]*(p+q+r);
	for(ll i=0;i<n;i++)
	{
		ll P,R;
		if(p<0)
		P=Mins[i];
		else
		P=Maxs[i];
		if(r<0)
		R=Minf[i];
		else
		R=Maxf[i];
		x=max(x,p*P+q*a[i]+r*R);
	}
	cout<<x;
}