#include<bits/stdc++.h>
#define  pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define vll vector<ll>
#define vvll vector<vector<ll> >
typedef long long ll;
using namespace std;
int main()
{
 ll n,k,m;
 cin>>n>>k>>m;
 ll a[k],s=0;
 for(ll i=0;i<k;i++)
 {
 cin>>a[i];
 s+=a[i];
 }
 sort(a,a+k);
 ll ans;
 ll Max=0;
 ll space;
 for(ll i=0;i<=n;i++)
 {
 	if(s*i>m)
 	break;
 	space=m-s*i;
 	ans=i*(k+1);
 	ll j=0;
 	ll N=n-i;
 	for(j=0;j<k;j++)
 	{
 		ans+=min(N,(space/a[j]));
 		space-=(min(N,(space/a[j])))*a[j];
	}
	Max=max(Max,ans);
 }
 cout<<Max;
}