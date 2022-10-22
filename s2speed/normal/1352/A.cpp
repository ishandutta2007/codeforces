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
		vector<ll> ans;
		ll n;
		cin>>n;
		for(int i = 0 ; n > 0 ; i++ , n /= 10){
			if(n % 10 != 0){
				ans.push_back((n % 10) * tav(10 , i));
			}
		}
		cout<<ans.size()<<endl;
		for(int i = 0 ; i < ans.size() ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		ans.clear();
	}
	return 0;
}