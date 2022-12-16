#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
const ll maxn=1e5+10;
ll a[maxn];
bool mark[maxn];
vector<ll> v;
int main()
{
	ll n;cin>>n;for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		ll num=0,tmp=a[i];
		while(!mark[tmp]) {mark[tmp]=1;tmp=a[tmp];num++;}
		if(num!=0) v.PB(num);
	}
	sort(v.begin(),v.end(),greater<ll>());
	if(v.size()==1) {cout<<v[0]*v[0];return 0;}
	ll ans=(v[0]+v[1])*(v[0]+v[1]);
	for(ll i=2;i<v.size();i++) ans+=v[i]*v[i];
	cout<<ans;
}