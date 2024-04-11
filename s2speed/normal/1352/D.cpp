#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		vector<ll> v;
		ll n , h , ansa = 0 , ansb = 0 , pa , pb = 0 , A = 0 , B , counter = 0;
		cin>>n;
		B = n - 1;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		for(int i = 0 ; A <= B ; i++){
			if(i % 2 == 0){
				pa = 0;
				while(pa <= pb && A <= B){
					ansa += v[A];
					pa += v[A];
					A++;
				}
			} else {
				pb = 0;
				while(pb <= pa && A <= B){
					ansb += v[B];
					pb += v[B];
					B--;
				}
			}
			counter++;
		}
		cout<<counter<<" "<<ansa<<" "<<ansb<<endl;
		v.clear();
	}
	return 0;
}