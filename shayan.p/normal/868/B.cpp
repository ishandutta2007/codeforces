#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll inf=1e18;
using namespace std;
int main()
{
	ll h,m,s,t1,t2;cin>>h>>m>>s>>t1>>t2;h=h%12;
	h=(h*2+((m+s>0)?1:0));m=(m/5)*2+(((m%5)+s>0)?1:0);s=(s/5)*2+((s%5>0)?1:0);t1=(t1*2)%24;t2=(t2*2)%24;
	ll both=0;vector<ll> v;
	for(ll i=0;i<24;i++)
	{
		if(i==t1||i==t2) {if(++both==2) {cout<<"YES";return 0;}}
		if(i==h||i==m||i==s) {both=0;v.PB(i);}
	}
	if(v.size()==1) {cout<<"YES";return 0;}
	both=0;
	for(ll i=v[v.size()-1];i!=v[0];i=(i+1)%24)
		{if(i==t1||i==t2) {if(++both==2) {cout<<"YES";return 0;}}	}
		if(v[0]==t1||v[0]==t2) {if(++both==2) {cout<<"YES";return 0;}}
		cout<<"NO";
}