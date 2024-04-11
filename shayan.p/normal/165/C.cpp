#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
ll f(ll num) {return (((num*(num-1))/2)+num);}
int main()
{
	ll n,ans=0;cin>>n;string s;cin>>s;
	vector<ll>v;
	v.PB(-1);
	for(ll i=0;i<s.size();i++)if(s[i]=='1')v.PB(i);
	v.PB(s.size());
	for(ll i=1;i<v.size()-n;i++) 
	{
	if(n==0)ans+=f(v[i]-v[i-1]-1);
	else ans+=(v[i]-v[i-1])*(v[i+n]-v[i+n-1]);
	}
	cout<<ans;
}