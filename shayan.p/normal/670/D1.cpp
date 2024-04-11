#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
ll ans=0,n,k,a[110000],b[110000];
bool pos(ll z)
{
	ll num=0;
	for(ll i=0;i<n;i++)
	{
		if(z*a[i]>b[i])
		num+=(z*a[i])-b[i];
	}
	if(num<=k) return 1;
	return 0;
}
void binary(ll q,ll w)
{
	if(q>w) return ;
	ll mid=(q+w)/2;
	if(pos(mid)) {ans=mid;binary(mid+1,w);}
	else binary(q,mid-1);
}
int main()
{
	cin>>n>>k;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];
	binary(0,(b[0]+k)/a[0]);
	cout<<ans;
}