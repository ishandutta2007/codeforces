#include<bits/stdc++.h>
#define ll long long
#define MP make_pair
#define PB push_back
#define pll pair<ll,ll>
#define F first
#define S second
using namespace std;
ll gcd(ll a,ll b) {if(b==0) return a;return gcd(b,a%b);}
const ll maxn=1e12+10;
const ll SQRT=1e6+10;
bool mark[SQRT];
vector<pll> divisor; // div,num
ll a,b,ans;
void tajzie()
{
	ll cop=a;
	for(ll i=2;i<SQRT;i++)
	{
		if(mark[i]==0)
		{
			ll num=0;
			while(cop%i==0) {num++;cop/=i;}
			if(num!=0) divisor.PB(MP(i,num)); 
			for(ll j=i*i;j<SQRT;j+=i) mark[j]=1;
		}
	}
	if(cop>1) divisor.PB(MP(cop,1));
}
void taghsim(ll g)
{
	for(ll i=0;i<divisor.size();i++)
	{
		if(g==1) return;
		while(g%divisor[i].F==0) {g/=divisor[i].F;divisor[i].S--;}
	}
}
int main()
{
	cin>>a>>b;
	tajzie();
	while(b>0)
	{
		ll g=gcd(a,b);a/=g;b/=g;taghsim(g);
		ll x=b%a;if(x==0) {ans+=(b/a);break;}
		ll Min=a;
		for(ll i=0;i<divisor.size();i++)
		{
			if(divisor[i].S==0)continue;
			Min=min(Min,(x%divisor[i].F));
		}
		ans+=Min;
		b-=Min;
	}
	cout<<ans;
}