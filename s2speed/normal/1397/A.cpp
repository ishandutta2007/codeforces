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

ll counter[26];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		bool ans = true;
		for(int i = 0 ; i < 26 ; i++){
			counter[i] = 0;
		}
		ll n;
		string h;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			ll hs = h.size();
			for(int i = 0 ; i < hs ; i++){
				ll p = h[i] - 'a';
				counter[p]++;
			}
		}
		for(int i = 0 ; i < 26 ; i++){
			if(counter[i] % n != 0){
				ans = false;
				break;
			}
		}
		if(ans == true){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}