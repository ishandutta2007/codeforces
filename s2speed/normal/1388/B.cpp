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
		string ans;
		ll n , p;
		cin>>n;
		p = n;
		for(int i = 0 ; i < n ; i++ , p -= 4){
			if(p > 0){
				ans += "8";
			} else {
				ans += "9";
			}
		}
		reverse(ans.begin() , ans.end());
		cout<<ans<<"\n";
	}
	return 0;
}