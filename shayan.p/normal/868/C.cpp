#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll inf=1e18;
using namespace std;

ll n,k,a[110000][10],num[20];
bool good(ll x)
{
	for(ll i=0;i<n;i++)
	if(a[i][x]==0) return 1;
	return 0;
}
int main()
{
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	for(ll j=0;j<k;j++)
	cin>>a[i][j];
	for(ll i=0;i<n;i++)
	{
		ll s=0;for(ll j=0;j<k;j++) s+=a[i][j];
		if(s==0) {cout<<"YES";return 0;}
		if(s==1)
		{
			ll g;
			for(ll j=0;j<k;j++) if(a[i][j]==1) g=j;
			if(good(g)) {cout<<"YES";return 0;}
			break;
		}
	}
	if(k==4)
	{
		for(ll i=0;i<n;i++) num[8*a[i][0]+4*a[i][1]+2*a[i][2]+a[i][3]]++;
		for(ll i=0;i<15;i++) if(num[i]>0&&num[15-i]>0) {cout<<"YES";return 0;}
	}
	cout<<"NO";
}