#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 0;

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

void solve(){
	bool ans = true;
	double n , k , d , c , x = 0 , y = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		x += k;
		c = sqrt(x * x + y * y);
		y += k;
		d = sqrt(x * x + y * y);
		if(c <= n && d > n){
			ans = true;
			break;
		}
		if(c > n && d > n){
			ans = false;
			break;
		}
	}
	if(ans){
		cout<<"Ashish\n";
	} else {
		cout<<"Utkarsh\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}