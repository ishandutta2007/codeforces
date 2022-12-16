#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=110;
ll a[maxn];
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
		{
			ll x;cin>>x;if(i==j) continue;
			for(ll k=0;k<=30;k++)
			{
				if(x%2==1)
				{
					if(((a[i]>>k)%2)==0) a[i]+=(1<<k);
					if(((a[j]>>k)%2)==0) a[j]+=(1<<k);
				}
				x/=2;
			}
		}
		for(ll i=0;i<n;i++) cout<<a[i]<<" ";
}