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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , z , counter = 0 , h = -1;
		string s , ans;
		cin>>n>>s;
		z = n;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '1'){
				z = i;
				break;
			}
			ans += "0";
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			if(s[i] == '0'){
				h = i;
				break;
			}
		}
		if(h != z - 1){
			ans += "0";
		}
		for(int i = n - 1 ; i > h ; i--){
			ans += "1";
		}
		cout<<ans<<"\n";
		ans.clear();
	}
	return 0;
}