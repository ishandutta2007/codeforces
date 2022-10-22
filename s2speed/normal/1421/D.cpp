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
	bool fr = false;
	ll x , y , ans = 0;
	cin>>x>>y;
	ll c[6];
	for(int i = 0 ; i < 6 ; i++){
		cin>>c[i];
	}
	c[0] = min(c[0] , c[1] + c[5]);
	c[3] = min(c[3] , c[2] + c[4]);
	c[5] = min(c[5] , c[0] + c[4]);
	c[1] = min(c[1] , c[0] + c[2]);
	c[2] = min(c[2] , c[3] + c[1]);
	c[4] = min(c[4] , c[3] + c[5]);
	if(x < 0 && y < 0){
		x -= 2 * x; y -= 2 * y;
		ll m = min(x , y);
		ans = m * c[3];
		x -= m;
		y -= m;
		ans += x * c[2] + y * c[4];
		fr = true;
	}
	if(fr == true){
		cout<<ans<<"\n";
		return;
	}
	if(x >= 0 && y >= 0){
		ll m = min(x , y);
		ans = m * c[0];
		x -= m;
		y -= m;
		ans += x * c[5] + y * c[1];
		fr = true;
	}
	if(fr == true){
		cout<<ans<<"\n";
		return;
	}
	if(x < 0 && y >= 0){
		x -= 2 * x;
		ans += x * c[2] + y * c[1];
		fr = true;
	}
	if(fr == true){
		cout<<ans<<"\n";
		return;
	}
	if(x >= 0 && y < 0){
		y -= 2 * y;
		ans += x * c[5] + y * c[4];
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