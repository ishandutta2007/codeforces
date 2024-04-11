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

const ll maxn = 2e5 + 16 , md = 998244353 , inf = 2e16;

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

map<ll , ll> cnt;
vector<ll> v;

void solve(){
	cnt.clear();
	v.clear();
	ll n , ans = 0 , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		cnt[h]++;
		v.push_back(h);
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		ll h = v[i] , o = h * k;
		if(!cnt[h]) continue;
		cnt[h]--;
		if(cnt[o] > 0){
			cnt[o]--;
		} else {
			ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
4 4
1 16 4 4
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}