#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<ll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	ll pr = -1 , cnt = 1 , m = -1 , ind = -1;
	for(ll i = 3 ; i <= n ; i++){
		cout<<"? 1 2 "<<i<<endl;
		ll h;
		cin>>h;
		cnt -= (pr != h);
		pr = h;
		if(h > m){
			m = h;
			ind = i;
		}
	}
	if(cnt == 0){
		for(ll i = 3 ; i <= n ; i++) v.push_back(i);
		if(n % 2 == 1) v.push_back(3);
		ll vs = sze(v);
		for(ll i = 0 ; i < vs ; i += 2){
			cout<<"? 1 "<<v[i]<<' '<<v[i + 1]<<endl;
			ll h;
			cin>>h;
			if(h > m){
				cout<<"! "<<v[i]<<' '<<v[i + 1]<<endl;
				return;
			}
		}
		cout<<"! 1 2"<<endl;
		return;
	}
	m = -1;
	ll jnd = -1;
	for(ll i = 1 ; i <= n ; i++){
		if(i != ind) v.push_back(i);
	}
	if(n % 2 == 0){
		v.push_back(1);
	}
	ll vs = sze(v);
	for(ll i = 0 ; i < vs ; i += 2){
		cout<<"? "<<ind<<' '<<v[i]<<' '<<v[i + 1]<<endl;
		ll h;
		cin>>h;
		if(h > m){
			m = h;
			jnd = i;
		}
	}
	ll q = 1;
	while(true){
		if(q == ind){
			q++;
			continue;
		}
		if(q == v[jnd]){
			q++;
			continue;
		}
		if(q == v[jnd + 1]){
			q++;
			continue;
		}
		break;
	}
	cout<<"? "<<ind<<' '<<v[jnd]<<' '<<q<<endl;
	ll h;
	cin>>h;
	if(h == m){
		cout<<"! "<<ind<<' '<<v[jnd]<<endl;
	} else {
		cout<<"! "<<ind<<' '<<v[jnd + 1]<<endl;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}