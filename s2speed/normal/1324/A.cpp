#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , t;
	cin>>t;
	while(t > 0){
		cin>>n;
		ll a;
		set<ll> s;
		for(int i = 0 ; i < n ; i++){
			cin>>a;
			s.insert(a % 2);
		}
		if(s.size() == 1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		s.clear();
		t--;
	}
	return 0;
}