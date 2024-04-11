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
		ll n , f = -1 , ans = 0 , counter = 0;
		char h;
		string s;
		cin>>n>>s;
		h = s[0];
		for(int i = 0 ; i < n - 1 ; i++){
			if(s[i] != s[i + 1]){
				f = i + 1;
				break;
			}
		}
		if(f == -1){
			if(n >= 3){
				ans++;
				ans += (n - 1) / 3;
			}
		}
		else{
			counter = 1;
			h = s[f];
			for(int i = f + 1 ; i != f ; i++){
				if(i == n) i = 0;
				if(s[i] != h){
					h = s[i];
					ans += counter / 3;
					counter = 0;
				}
				counter++;
			}
		}
		ans += counter / 3;
		cout<<ans<<"\n";
	}
	return 0;
}