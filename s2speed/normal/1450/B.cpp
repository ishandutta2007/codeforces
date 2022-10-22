#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 100 + 20;
 
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

vector<pll> q;

ll gh(ll a , ll b){
	return max(a - b , b - a);
}

void solve(){
	bool ans = false;
	ll n , k;
	cin>>n>>k;
	q.clear();
	for(int i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y;
		q.push_back( {x , y} );
	}
	for(int i = 0 ; i < n ; i++){
		ll cnt = 0;
		for(int j = 0 ; j < n ; j++){
			if(gh(q[i].first , q[j].first) + gh(q[i].second , q[j].second) <= k){
				cnt++;
			}
		}
		if(cnt == n){
			ans = true;
			break;
		}
	}
	if(ans){
		cout<<"1\n";
	} else {
		cout<<"-1\n";
	}
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