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

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < i ; j++){
			cout<<"0 ";
		}
		cout<<"1 1 ";
		for(int j = i + 2 ; j < n ; j++){
			cout<<"0 ";
		}
		cout<<"\n";
	}
	cout<<"1 ";
	for(int i = 0 ; i < n - 2 ; i++){
		cout<<"0 ";
	}
	cout<<"1\n";
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