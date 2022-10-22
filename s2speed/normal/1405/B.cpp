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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , h , counter = 0 , ans = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			counter += h;
			if(counter < 0){
				ans += 0 - counter;
				counter = 0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}