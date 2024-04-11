#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

void solve(){
	ll n , k;
	string ans;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		if(i % 3 == 0){
			ans += 'a';
		} else if(i % 3 == 1){
			ans += 'b';
		} else {
			ans += 'c';
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}