#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1e5 + 20;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
	}
	return res;
}

ll c[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k , ans = 1e9;
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>c[i];
		}
		for(int j = 1 ; j <= 100 ; j++){
			ll h = 0 , x = 0;
			while(x < n){
				if(c[x] != j){
					x += k;
					h++;
				} else {
					x++;
				}
			}
			ans = min(ans , h);
		}
		cout<<ans<<'\n';
	}
	return 0;
}