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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool e = false;
		string ans;
		ll a , b , c;
		cin>>a>>b>>c;
		if(a == 0 && b == 0){
			for(int i = 0 ; i <= c ; i++){
				ans += "1";
			}
			cout<<ans<<endl;
			continue;
		} else if(a == 0 && c == 0){
			for(int i = 0 ; i <= b ; i++){
				if(i % 2 == 0){
					ans += "0";
				} else {
					ans += "1";
				}
			}
			cout<<ans<<endl;
			continue;
		} else if(a == 0){
			for(int i = 0 ; i <= c ; i++){
				ans += "1";
			}
			for(int i = 0 ; i < b ; i++){
				if(i % 2 == 0){
					ans += "0";
				} else {
					ans += "1";
				}
			}
			cout<<ans<<endl;
			continue;
		} else if(c == 0 && b == 0){
			for(int i = 0 ; i <= a ; i++){
				ans += "0";
			}
			cout<<ans<<endl;
			continue;
		} else if(c == 0){
			for(int i = b ; i >= 0 ; i--){
				if(i % 2 == 0){
					ans += "0";
				} else {
					ans += "1";
				}
			}
			for(int i = 0 ; i < a ; i++){
				ans += "0";
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i = 0 ; i <= c ; i++){
			ans += "1";
		}
		if(b % 2 == 0){
			e = true;
			b--;
		}
		for(int i = 0 ; i < b / 2 ; i++){
			ans += "01";
		}
		for(int i = 0 ; i <= a ; i++){
			ans += "0";
		}
		if(e == true){
			ans += "1";
		}
		cout<<ans<<endl;
	}
	return 0;
}