#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second
//#define cin fin
//std::ifstream fin("my code.txt");
using namespace std;
const ll maxn=1e5+10;
const double pi=3.14159265358979323846;
ll n,tree[maxn],dp,Max;
ll ask(ll index)
{
	ll ans=0;
	while(index>0)
	{
		ans=max(ans,tree[index]);
		index-=(index & -index);
	}
	return ans;
}
void update(ll index,ll x)
{
	while(index<=n)
	{
		tree[index]=max(tree[index],x);
		index+=(index & -index);
	}
}
map<ll,ll> hf;
int main()
{
	cin>>n;ll v[n+10],cop[n+10];for(ll i=1;i<=n;i++) {ll r,h;cin>>r>>h;v[i]=r*r*h;cop[i]=v[i];}
	sort(cop+1,cop+n+1);
	for(ll i=1;i<=n;i++) hf[cop[i]]=i;
	for(ll i=1;i<=n;i++)
	{
		dp=v[i]+ask(hf[v[i]]-1);
		update(hf[v[i]],dp);
		Max=max(Max,dp);
	}
	cout<<setprecision(9)<<fixed;
	cout<<double(Max)*pi;
}