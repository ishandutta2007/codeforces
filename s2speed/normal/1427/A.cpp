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

vector<ll> v;

void solve(){
	v.clear();
	ll n , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		sum += inp;
		v.push_back(inp);
	}
	if(sum == 0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	sort(v.begin() , v.end());
	if(sum > 0){
		reverse(v.begin() , v.end());
	}
	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
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