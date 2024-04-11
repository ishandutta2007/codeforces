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

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool b = true;
		ll ans = 0 , o = 0 , n , k;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){
				o++;
			} else {
				if(b == true){
					ans += max(z , o / (k + 1));
					b = false;
				} else {
					ans += max(z , (o + 1) / (k + 1)) - 1;
				}
				o = 0;
			}
		}
		if(b == true){
			ans += max(z , (o + k) / (k + 1));
		} else {
			ans += max(z , o / (k + 1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}