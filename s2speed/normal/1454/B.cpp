#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

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
	bool ans = true;
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		a[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		ll b;
		cin>>b;
		b--;
		if(a[b] == -1){
			a[b] = i;
		} else {
			a[b] = -2;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] >= 0){
			ans = false;
			cout<<a[i] + 1<<"\n";
			break;
		}
	}
	if(ans){
		cout<<"-1\n";
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