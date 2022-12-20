#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
const ll maxn=1e6+10;
ll tree[maxn],n;
pll a[maxn];
ll ask(ll ind)//available 1 ,...,ind
{
	ll ans=0;
	while(ind>0)
	{
		ans+=tree[ind];
		ind-=(ind & -ind);
	}
	return ans;
}
void upd(ll ind)//ind available
{
	while(ind<=n)
	{
		tree[ind]++;
		ind+=(ind & -ind);
	}
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++){cin>>a[i].F;a[i].S=i;}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){a[i].F=a[i].S;a[i].S=i;}// F index  S value
	sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll x=a[i].S;ll Ask=ask(x-1);
		ans+=(i-1-Ask)*(x-1-Ask);
		upd(x);
	}
	cout<<ans;
}