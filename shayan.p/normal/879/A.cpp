#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
ll next(ll now,ll s,ll d)
{
	if(now<s) return s;
	ll N=now%d,S=s%d;
	if(N<S) return now+S-N;
	if(N==S) return now+d;
	if(N>S) return now+d-N+S;
}
int main()
{
	ll n;cin>>n;
	ll now=0;
	for(ll i=0;i<n;i++)
	{
		ll s,d;cin>>s>>d;
		now=next(now,s,d);
	}
	cout<<now;
}