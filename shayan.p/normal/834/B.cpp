#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll Start[30],End[30];
int main()
{
	fill(Start,Start+30,-1);
	fill(End,End+30,-1);
	ll n,k;cin>>n>>k;
	string s;cin>>s;
	for(ll i=0;i<n;i++){
		if(Start[s[i]-'A']==-1)Start[s[i]-'A']=i;
		End[s[i]-'A']=i;
	}
	ll num=0;
	for(ll i=0;i<n;i++){
		if(i==Start[s[i]-'A'])num++;
		if(num>k){cout<<"YES";return 0;}
		if(i==End[s[i]-'A'])num--;
	}
	cout<<"NO";
}