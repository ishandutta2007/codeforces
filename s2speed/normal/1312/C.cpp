#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll k){
	ll h = 1;
	while(h <= 1e16 / k){
		h *= k;
	}
	return h;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t > 0){
		bool ch = true;
		ll n , k , h;
		vector<ll> v;
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		h = tav(k);
		while(h > 0){
			ll s = 0;
			for(int i = 0 ; i < n ; i++){
				s += v[i] / h;
				v[i] %= h;
			}
			h /= k;
			if(s > 1){
				ch = false;
				break;
			}
		}
		if(ch == true){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		v.clear();
		t--;
	}
	return 0;
}