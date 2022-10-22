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
	bool r = false , b = false;
	ll n;
	string s;
	cin>>n>>s;
	for(int i = 1 ; i <= n ; i++){
		ll h = s[i - 1] - '0';
		if(i % 2 == 1 && h % 2 == 1){
			r = true;
		} else if(i % 2 == 0 && h % 2 == 0){
			b = true;
		}
	}
	if(n % 2 == 0){
		if(b == true){
			cout<<"2\n";
		} else {
			cout<<"1\n";
		}
	} else {
		if(r == true){
			cout<<"1\n";
		} else {
			cout<<"2\n";
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