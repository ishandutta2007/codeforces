#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 1000;

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

ll a[MAX_N][MAX_N];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>a[i][j];
			if(a[i][j] % 2 != (i + j) % 2){
				a[i][j]++;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
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