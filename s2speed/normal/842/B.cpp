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

ll n , k , ans = 0;

void solve(){
	double x , y , r , d;
	cin>>x>>y>>r;
	d = sqrt(x * x + y * y);
	if(d - r >= k && d + r <= n){
		ans++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;
	k = n - k;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	cout<<ans<<"\n";
	return 0;
}