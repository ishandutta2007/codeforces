#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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

set<ll> s;

void solve(){
	ll n , k;
	cin>>n>>k;
	s.clear();
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		s.insert(inp);
	}
	if(k == 1 && s.size() > 1){
		cout<<"-1\n";
		return;
	} else if(k == 1){
		cout<<"1\n";
		return;
	}
	ll h = s.size(); h--; k--;
	if(h == 0){
		cout<<"1\n";
		return;
	}
	cout<<(h + k - 1) / k<<"\n";
	return;	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}