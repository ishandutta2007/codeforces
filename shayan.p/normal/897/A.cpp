#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	ll n,m;cin>>n>>m;
	string s;cin>>s;
	for(ll i=0;i<m;i++){
		ll l,r;cin>>l>>r;
		char c1,c2;cin>>c1>>c2;
		l--;r--;
		for(l;l<=r;l++){
			if(s[l]==c1)s[l]=c2;
		}
	}
	cout<<s;
}