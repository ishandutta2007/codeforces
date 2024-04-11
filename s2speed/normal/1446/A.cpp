#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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

vector<ll> v;

void solve(){
	bool ans = false;
	ll n , w , s = 0;
	cin>>n>>w;
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		if(ans){
			continue;
		}
		if(inp < (w + 1) / 2){
			v.push_back(i);
			s += inp;
		} else if(inp <= w){
			v.clear();
			v.push_back(i);
			s = inp;
		}
		if(s >= (w + 1) / 2 && s <= w){
			ans = true;
		}
	}
	if(!ans){
		cout<<"-1\n";
		v.clear();
		return;
	}
	cout<<v.size()<<"\n";
	for(auto i : v){
		cout<<i + 1<<" ";
	}
	cout<<"\n";
	v.clear();
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