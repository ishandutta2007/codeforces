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

ll b[32];

ll b2(ll h){
	ll o = tav(2 , 31) , counter = 31;
	while(h < o){
		o /= 2;
		counter--;
	}
	return counter;
}

void solve(){
	ll ans = 0;
	for(int i = 0 ; i < 32 ; i++){
		b[i] = 0;
	}
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		ll p = b2(h);
		b[p]++;
	}
	for(int i = 0 ; i < 32 ; i++){
		ans += b[i] * (b[i] - 1) / 2;
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