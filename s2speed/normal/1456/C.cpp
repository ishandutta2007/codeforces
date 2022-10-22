#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 5e5 + 20;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
	}
	return res;
}

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k , ans = 0 , x = 0 , h = 0 , q , z;
	cin>>n>>k;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end() , greater<ll>());
	for(; x < n ; x++){
		ans += h;
		h += v[x];
		if(h < 0){
			q = h;
			break;
		}
	}
	k++;
	for(int i = n - k - 1 ; i >= x ; i--){
		z = (n - 1 - i) / k;
		if(i == x){
			ans += z * q * 1ll;
			break;
		}
		ans += z * v[i] * 1ll;
	}
	cout<<ans<<'\n';
	return 0;
}