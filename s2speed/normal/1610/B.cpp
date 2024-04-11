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

ll a[maxn];
vector<ll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll r = -1;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] == a[n - i - 1]) continue;
		r = i;
		break;
	}
	if(r == -1){
		cout<<"YES\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		if(a[i] != a[r]) v.push_back(a[i]);
	}
	ll vs = sze(v);
	bool f = true;
	for(ll i = 0 ; i < vs ; i++){
		if(v[i] != v[vs - i - 1]){
			f = false;
			break;
		}
	}
	if(f){
		cout<<"YES\n";
		return;
	}
	v.clear();
	r = n - r - 1;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] != a[r]) v.push_back(a[i]);
	}
	vs = sze(v);
	f = true;
	for(ll i = 0 ; i < vs ; i++){
		if(v[i] != v[vs - i - 1]){
			f = false;
			break;
		}
	}
	if(f){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}