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

const ll z = 0;
ll a[500];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool ans = true;
		ll n , h , v0 = 0 , v1 = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			if(h == 0){
				v0++;
			} else {
				v1++;
			}
		}
		if(v1 > 0 && v0 > 0){
			cout<<"Yes\n";
		} else {
			for(int i = 1 ; i < n && ans == true ; i++){
				if(a[i] < a[i - 1]){
					ans = false;
				}
			}
			if(ans == true){
				cout<<"Yes\n";
			} else {
				cout<<"No\n";
			}
		}
	}
	return 0;
}