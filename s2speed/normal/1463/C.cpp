#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
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

ll t[MAX_N] , x[MAX_N];

void solve(){
	ll n , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>t[i]>>x[i];
	}
	ll y = 0 , k = 0;
	for(int i = 0 ; i < n - 1 ; i++){
		ll d = y;
		if(x[k] < y){
			y = max(x[k] , y - (t[i + 1] - t[i]));
		}
		if(x[k] > y){
			y = min(x[k] , y + t[i + 1] - t[i]);
		}
		if(y == x[k]){
			k = i + 1;
		}
		if(x[i] >= min(d , y) && x[i] <= max(d , y)){
			ans++;
		}
	}
	if((y >= x[n - 1] && x[k] <= x[n - 1]) || (y <= x[n - 1] && x[k] >= x[n - 1])){
		ans++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}