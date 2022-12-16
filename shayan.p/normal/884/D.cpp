#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
multiset<ll>s;
int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		s.insert(x);
	}
	if(n%2==0){
		s.insert(0);
	}
	while(s.size()>1){
		if(s.size()>2){
			ll x=0;
			x+=(*s.begin());
			s.erase(s.begin());
			x+=(*s.begin());
			s.erase(s.begin());
			x+=(*s.begin());
			s.erase(s.begin());
			ans+=x;
			s.insert(x);
		}
		else{
			ll x=0;
			x+=(*s.begin());
			s.erase(s.begin());
			x+=(*s.begin());
			s.erase(s.begin());
			ans+=x;
			s.insert(x);
		}
	}
	cout<<ans;
}