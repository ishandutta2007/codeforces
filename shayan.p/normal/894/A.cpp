#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll qs[110],ans;
int main()
{
	string s;cin>>s;
	for(ll i=1;i<=s.size();i++)qs[i]=qs[i-1]+(s[i-1]=='Q');
	ll tot=qs[s.size()];
	for(ll i=1;i<=s.size();i++){
		if(s[i-1]=='A')
		ans+=qs[i]*(tot-qs[i]);
	}
	cout<<ans;
}