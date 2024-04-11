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

bool ch(string s){
	ll a = 0 , b = 0 , c = 0;
	for(int i = 0 ; i < 3 ; i++){
		if(s[i] == '1'){
			a++;
		} else if(s[i] == '2'){
			b++;
		} else {
			c++;
		}
	}
	if(a == 1 && b == 1){
		return true;
	} else {
		return false;
	}
}

const ll z = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll ans = 0 , k;
		vector<ll> v;
		string s , h;
		cin>>s;
		h += s[0];
		v.push_back(1);
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] != s[i - 1]){
				v.push_back(1);
				h += s[i];
				if(h.size() > 2){
					if(ch(h.substr(h.size() - 3 , 3)) == true){
						k = 2 + v[v.size() - 2];
						if(ans == 0){
							ans = k;
						} else {
							ans = min(ans , k);
						}
					}
				}
			} else {
				v[v.size() - 1]++;
			}
		}
		cout<<ans<<"\n";
		h.clear();
		v.clear();
	}
	return 0;
}