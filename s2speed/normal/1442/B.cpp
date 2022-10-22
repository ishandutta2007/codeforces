#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5 + 20 , md = 998244353;

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

ll a[MAX_N] , p[MAX_N] , b[MAX_N];
bool o[MAX_N];

void solve(){
	ll n , k , ans = 1;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		p[a[i]] = i;
		o[i] = true;
	}
	for(int i = 0 ; i < k ; i++){
		cin>>b[i]; b[i]--;
		o[p[b[i]]] = false;
	}
	for(int i = 0 ; i < k ; i++){
		ll u = p[b[i]] , h = 0;
		if(u > 0){
			if(o[u - 1]){
				h++;
			}
		}
		if(u < n - 1){
			if(o[u + 1]){
				h++;
			}
		}
		ans *= h;
		ans %= md;
		o[u] = true;
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