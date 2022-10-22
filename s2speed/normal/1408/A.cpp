#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 100;

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

ll a[MAX_N] , b[MAX_N] , c[MAX_N] , ans[MAX_N];

void solve(){
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>c[i];
	}
	ans[0] = a[0];
	for(int i = 1 ; i < n - 1 ; i++){
		if(a[i] != ans[i - 1]){
			ans[i] = a[i];
		} else {
			ans[i] = b[i];
		}
	}
	if(a[n - 1] != ans[n - 2] && a[n - 1] != ans[0]){
		ans[n - 1] = a[n - 1];
	} else if(b[n - 1] != ans[n - 2] && b[n - 1] != ans[0]){
		ans[n - 1] = b[n - 1];
	} else {
		ans[n - 1] = c[n - 1];
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
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