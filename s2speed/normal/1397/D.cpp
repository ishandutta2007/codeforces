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

void solve(){
	ll n , sum = 0 , m = 0;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
		m = max(m , v[i]);
		sum += v[i];
	}
	if(sum % 2 == 1){
		cout<<"T\n";
		v.clear();
		return;
	}
	if(m > sum / 2){
		cout<<"T\n";
		v.clear();
		return;
	}
	cout<<"HL\n";
	v.clear();
	return;
	
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