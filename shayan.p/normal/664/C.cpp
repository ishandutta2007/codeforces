#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll E(ll a)
{
	ll ans=1;for(ll i=0;i<a;i++) ans*=10;
	return ans;
}
ll make_num(string s)
{
	ll ans=0;
	for(ll i=0;i<s.size();i++) ans=ans*10+s[i]-'0';
	return ans;
}
ll f(string s)//whitch year makes num?
{
	if(s.size()==1) for(ll i=1989;;i++) if(i%10==s[0]-'0') return i;
	ll num2=f(s.substr(1));
	ll T=E(s.size()-1);
	ll num=make_num(s);
	for(ll i=num2+T;;i+=T) if(i%(T*10)==num) return i;
}
int main()
{
	ll n;cin>>n;for(ll i=0;i<n;i++) {string s;cin>>s;cout<<f(s.substr(4))<<endl;}
}