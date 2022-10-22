#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll z = 0;

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

ll m2(ll n){
	ll h = tav(2 , 8);
	for(int i = 8 ; i >= 0 ; i--){
		if(n >= h) return h;
		h /= 2;
	}
}

vector<ll> v;

ll a[200] , b[200];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , m , oa = 0 , ab = 511 , ans , h , o;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		oa = oa | a[i];
	}
	for(int i = 0 ; i < m ; i++){
		cin>>b[i];
		ab = ab & b[i];
	}
	ans = ab & oa;
	for(int i = 0 ; i < n ; i++){
		h = a[i];
		a[i] = a[i] ^ ans;
		a[i] = h & a[i];
	}
	for(int i = 0 ; i < m ; i++){
		h = b[i];
		b[i] = b[i] ^ ans;
		b[i] = h & b[i];
	}
	for(int q = 0 ; q < 9 ; q++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				o = a[i] & b[j];
				h = min(o , h);
			}
			if(h > 0) v.push_back(m2(h));
			h = 511;
		}
		if(v.size() == 0) break;
		sort(v.begin() , v.end());
		ans |= v[v.size() - 1];
		for(int i = 0 ; i < n ; i++){
			h = a[i];
			a[i] = a[i] ^ ans;
			a[i] = h & a[i];
		}
		for(int i = 0 ; i < m ; i++){
			h = b[i];
			b[i] = b[i] ^ ans;
			b[i] = h & b[i];
		}
		v.clear();
	}
	cout<<ans<<"\n";
	return 0;
}