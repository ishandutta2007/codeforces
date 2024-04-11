#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
ll select(ll n,ll k)
{
	ll ans=1;
	for(ll i=0;i<k;i++)ans*=n-i;
	for(ll i=1;i<=k;i++)ans/=i;
	return ans;
}
ll fact(ll num)
{
	ll ans=1;
	for(ll i=1;i<=num;i++)ans*=i;
	return ans;
}
ll parish(ll n)
{
	ll num=fact(n),manfi=-1;
	ll ans=num;
	for(ll i=1;i<=n;i++)
	{
		num/=i;
		ans+=num*manfi;
		manfi*=-1;
	}
	return ans;
}
ll f(ll n,ll k)//daghighan k ta ja be ja
{
	return select(n,k)*parish(k);
}
int main()
{
	ll n,k;cin>>n>>k;
	ll ans=0;
	for(k;k>=0;k--)ans+=f(n,k);
	cout<<ans;
}