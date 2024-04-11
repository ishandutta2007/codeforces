#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

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

void solve(){
	ll n;
	cin>>n;
	cout<<n<<" ";
	for(int i = 1 ; i < n ; i++){
		cout<<i<<" ";
	}
	cout<<"\n";
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