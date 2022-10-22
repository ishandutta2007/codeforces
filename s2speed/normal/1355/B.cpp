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
		ll n , h , ans = 0 , l = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		for(int i = 0 ; i < n ; i++){
			l++;
			if(l >= v[i]){
				ans++;
				l = 0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}