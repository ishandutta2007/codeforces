#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
ll ksm(ll x,ll y)
{
	ll r=1;
	while (y)
	{
		if (y&1) r=r*x%p;
		x=x*x%p;
		y>>=1;
	}
	return r;
}
ll n,m,k,ans,r,c,x[2],y[2];
int main()
{
	cin>>n>>m>>k>>r>>c>>x[0]>>y[0]>>x[1]>>y[1];
	if (x[0]>x[1]) swap(x[0],x[1]);
	if (y[0]>y[1]) swap(y[0],y[1]);
	if (x[0]==x[1]&&y[0]==y[1])
	{
		ans=ksm(k,n*m);
		cout<<ans;return 0;
	}
	cout<<ksm(k,n*m-r*c);
	return 0;
	if (x[0]+r<=y[0]&&x[1]+c<=y[1])
	{
		ans=ksm(k,n*m-r*c);
		cout<<ans;return 0;
	}
	x[1]-=x[0];y[1]-=y[0];
	ans=ksm(k,n*m-r*c*2+(r-x[1])*(c-y[1])+x[1]*c+y[1]*r-x[1]*y[1]);
	cout<<ans;
}