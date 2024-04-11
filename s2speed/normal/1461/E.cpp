#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 1e6 + 20;
 
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

bool mark[MAX_N] , safe[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll k , l , r , t , x , y , d , q , ans;
	cin>>k>>l>>r>>t>>x>>y;
	if(y < x){
		q = l + x - 1;
		d = k - q;
		d = d + x - y - 1;
		q = x - y;
		d /= q;
		ans = d;
		if(t <= ans){
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
		return 0;
	}
	for(ll i = l ; i < l + x ; i++){
		safe[i % x] = (r - i) >= y;
		mark[i % x] = false;
	}
	d = l / x;
	ll p , m , c = t , o = k;
	for(ll i = 0 ; i < x ; i++){
		m = o % x;
		if(mark[m]){
			break;
		}
		p = 1ll * d * x + m;
		if(p < l){
			p += x;
		}
		q = o - p; q /= x;
		c -= q;
		if(c <= 0){
			break;
		}
		if(safe[m]){
			o = p + y;
		} else {
			cout<<"No\n";
			return 0;
		}
		mark[m] = true;
	}
	cout<<"Yes\n";
	return 0;
}