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

vector<ll> v;

void solve(){
	bool a = false;
	ll n;
	cin>>n;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end());
	for(int i = 1 ; i < n ; i++){
		if(v[i] == v [i - 1]){
			a = true;
			break;
		}
	}
	if(a){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	v.clear();
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