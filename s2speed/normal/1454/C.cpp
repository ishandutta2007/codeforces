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

ll a[MAX_N];

void solve(){
	ll n , h , q , ans = 1e18 , b;
	cin>>n>>h; h--;
	b = h;
	for(int i = 0 ; i < n ; i++){
		a[i] = -1;
	}
	a[b] = 1;
	for(int i = 1 ; i < n ; i++){
		cin>>q;
		q--;
		if(q != h){
			if(a[q] == -1){
				a[q] = 0;
			}
			a[q]++;
		}
		h = q;
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] == -1){
			continue;
		}
		a[i] += (i != b) + (i != h);
		a[i]--;
		if(a[i] <= -1){
			continue;
		}
		ans = min(ans , a[i]);
	}
	cout<<ans<<"\n";
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