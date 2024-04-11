#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define PF push_front
using namespace std;
map<ll,ll> bef,aft;
bool check[1000010];
stack<ll> s;
ll choose()
{
	while(!s.empty())
	{
		if(!check[s.top()]&&s.top()!=0) return s.top();
		s.pop();
	}
}
deque<ll> go()
{
ll x=choose();ll last=x;deque<ll> d;d.PB(last);
while(aft.count(last)){last=aft[last];d.PB(last);}
last=x;
while(bef.count(last)){last=bef[last];d.PF(last);}
return d;	
}
int main()
{
	ll n;cin>>n;for(ll i=0;i<n;i++) {ll a,b;cin>>a>>b;s.push(a);aft[a]=b;bef[b]=a;}
	ll ans[n+10];
	ll last=0;
	for(ll i=2;i<=n;i+=2) {ans[i]=aft[last];last=ans[i];check[ans[i]]=1;}
	if(n%2==0) {last=0;for(ll i=n-1;i>0;i-=2){ans[i]=bef[last];last=ans[i];} }
	else {deque<ll> v=go();for(ll i=0;i<v.size();i++) ans[2*i+1]=v[i];} 
	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
}