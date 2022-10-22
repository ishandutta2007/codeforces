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

ll gh(ll a , ll b){
	if(a > b){
		return a - b;
	} else {
		return b - a;
	}
}

void solve(){
	ll n , ans = 1e14 , counter , h;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end());
	for(int i = 1 ; i < 1e6 ; i++){
		counter = 0;
		h = 1;
		for(int j = 0 ; j < n ; j++){
			ll k = gh(v[j] , h);
			counter += k;
			if(k > ans && h > v[j]){
				cout<<ans<<"\n";
				return;
			}
			h *= i;
		}
		ans = min(counter , ans);
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}