#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 3e5;

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

ll p[MAX_N] , a[MAX_N] , ans[MAX_N];

void solve(){
	ll n , x;
	cin>>n; x = n;
	for(int i = 0 ; i < n ; i++){
		p[i] = -1;
		ans[i] = -1;
		a[i] = -1;
	}
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp; inp--;
		a[inp] = max(a[inp] , i - p[inp]);
		p[inp] = i;
	}
	for(int i = 0 ; i < n ; i++){
		a[i] = max(a[i] , n - p[i]);
		a[i]--;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = a[i] ; j < x && j >= 0 ; j++){
			ans[j] = i + 1;
		}
		x = min(x , a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
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