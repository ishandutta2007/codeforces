#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

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

ll a[MAX_N] , b[MAX_N];

void solve(){
	ll n , x = 0 , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	b[n - 1] = -1;
	for(int i = n - 2 ; i >= 0 ; i--){
		if(a[i] == 1){
			b[i] = 0;
		} else if(b[i + 1] == -1){
			b[i] = -1;
		} else {
			b[i] = b[i + 1] + 1;
		}
	}
	for(int i = 0 ; i < n && x < n ; i++){
		if(i % 2 == 0){
			if(a[x] == 1){
				ans++;
			}
			x++;
			if(b[x] % 2 == 1){
				x++;
			}
		} else {
			x++;
			if(a[x] == 1){
				x++;
			}
		}
	}
	cout<<ans<<"\n";
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