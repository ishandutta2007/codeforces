#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t , n , x;
	cin>>t;
	while(t--){
		ll h , ans;
		set<ll> s;
		cin>>n>>x;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			s.insert(h);
		}
		h = 0;
		for(int i = 1 ; i <= 300 ; i++){
			if(s.find(i) == s.end()){
				h++;
			}
			if(h == x + 1){
				ans = i - 1;
				break;
			}
		}
		cout<<ans<<endl;
		s.clear();
	}
	return 0;
}