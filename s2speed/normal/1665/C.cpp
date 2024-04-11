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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

ll d[maxn];
vector<ll> v , s;

bool check(ll x){
	ll cnt = 0;
	for(auto i : s){
		cnt += max(0ll , i - x);
	}
	return (cnt <= x);
}

void solve(){
	v.clear(); s.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) d[i] = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll h;
		cin>>h; h--;
		d[h]++;
	}
	ll ans = 1;
	for(ll i = 0 ; i < n ; i++){
		if(!d[i]) continue;
		v.push_back(d[i]);
		ans++;
	}
	v.push_back(1);
	sort(all(v) , greater<ll>());
	for(ll i = 0 ; i < ans ; i++){
		ll h = v[i] - (ans - i);
		if(h > 0) s.push_back(h);
	}
	sort(all(s) , greater<ll>());
	ll l = -1 , r = n;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<ans + r<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}