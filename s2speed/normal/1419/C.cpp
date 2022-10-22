#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e3 + 1;

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

ll a[MAX_N];

void solve(){
	bool zero = true , one = false;
	ll n , sum = 0;
	cin>>n>>a[0];
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
		if(a[i] != a[0]){
			zero = false;
		} else {
			one = true;
		}
		sum += a[i];
	}
	if(zero == true){
		cout<<"0\n";
	} else if(sum == a[0] * n || one == true){
		cout<<"1\n";
	} else {
		cout<<"2\n";
	}
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