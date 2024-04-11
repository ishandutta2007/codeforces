#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

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
	ll n;
	cin>>n;
	if(n % 3 == 0){
		cout<<n / 3<<" 0 0\n";
	} else if(n % 3 == 1){
		if(n < 7){
			cout<<"-1\n";
		} else {
			n -= 7;
			cout<<n / 3<<" 0 1\n";
		}
	} else {
		if(n < 5){
			cout<<"-1\n";
		} else {
			n -= 5;
			cout<<n / 3<<" 1 0\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}