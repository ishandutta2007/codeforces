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

string solve(){
	ll x , n;
	string s , w , h;
	cin>>s>>x;
	n = s.size();
	for(int i = 0 ; i < n ; i++){
		h += "0";
		w += "1";
	}
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '0'){
			if(i - x >= 0){
				w[i - x] = '0';
			}
			if(i + x < n){
				w[i + x] = '0';
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(i - x >= 0){
			if(w[i - x] == '1') h[i] = '1';
		}
		if(i + x < n){
			if(w[i + x] == '1') h[i] = '1';
		}
	}
	if(h != s) return "-1";
	return w;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		string ans = solve();
		cout<<ans<<"\n";
	}
	return 0;
}