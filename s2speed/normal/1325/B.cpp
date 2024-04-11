#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n;
	cin>>t;
	while(t > 0){
		ll h;
		set<ll> s;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			s.insert(h);
		}
		cout<<s.size()<<endl;
		s.clear();
		t--;
	}
	return 0;
}