#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;cin>>n;
	set<ll>s;s.insert(0);
	for(ll i=1;i<=n;i++)
	{
		ll x;cin>>x;
		if(s.count(x)){s.erase(x);s.insert(i);}
		else s.insert(i);
	}
	cout<<s.size();
}