#include<bits/stdc++.h>
#define ll long long
#define pl5 pair<ll,pair<ll,pair<ll,pair<ll,ll> > > >
#define F first
#define S second
#define a F
#define b S.F
#define c S.S.F
#define d S.S.S.F
#define e S.S.S.S
#define PB push_back
using namespace std;
bool dot(pl5 x,pl5 y,pl5 targ)
{
	ll ans=0;
	ans+=(x.a-targ.a)*(y.a-targ.a);
	ans+=(x.b-targ.b)*(y.b-targ.b);
	ans+=(x.c-targ.c)*(y.c-targ.c);
	ans+=(x.d-targ.d)*(y.d-targ.d);
	ans+=(x.e-targ.e)*(y.e-targ.e);
	return (ans>0);
}
bool no[1100];
int main()
{
	ll n;cin>>n;pl5 D[n+10];
	for(ll i=0;i<n;i++)	cin>>D[i].a>>D[i].b>>D[i].c>>D[i].d>>D[i].e;
	if(n>32){cout<<0;return 0;}
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n&&!no[i];j++)
			for(ll k=j+1;k<n&&!no[i];k++)
			if(j!=i&&k!=i)
			if(dot(D[j],D[k],D[i]))no[i]=1;
		vector<ll>v;
		for(ll i=0;i<n;i++)	if(!no[i])v.PB(i+1);
		cout<<v.size();for(ll i=0;i<v.size();i++)cout<<endl<<v[i];
}