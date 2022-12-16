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
	string pas,word[1000];ll n;cin>>pas;cin>>n;for(ll i=0;i<n;i++) cin>>word[i];
	ll b0=0,b1=0;
	for(ll i=0;i<n;i++)
	{
		if(pas==word[i]) {cout<<"YES";return 0;}
		if(pas[0]==word[i][1]) b0++;
		if(pas[1]==word[i][0]) b1++;
	}
	if(b0==0||b1==0){cout<<"NO";return 0;}
	cout<<"YES";return 0;
}