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

const ll maxn = 4e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> dv[maxn] , v;
ll t[maxn];

void solve(){
	ll l , r;
	cin>>l>>r;
	ll d = r - l + 1 , ans = d * (d - 1) * (d - 2) / 6;
	for(ll i = l + 2 ; i <= r ; i++){
		ll j = lower_bound(all(dv[i]) , l) - dv[i].begin();
		ll h = sze(dv[i]) - j;
		ll res = h * (h - 1) / 2;
		ans -= res;
	}
	for(ll i = l + 2 ; i <= r ; i++){
		ll res = 0 , i2 = i << 1;
		v.clear();
		for(auto j : dv[i]){
			ll j2 = j << 1;
			if(j2 < l || t[j] != t[i]) continue;
			ll o = lower_bound(all(dv[i2]) , max(l , i - j2 + 1)) - dv[i2].begin();
			res += sze(dv[i2]) - o - 1;
			v.push_back(j2);
		}
		for(auto j : v){
			ll o = lower_bound(all(v) , max(j , i - j + 1)) - v.begin();
			res -= sze(v) - o;
		}
		ans -= res;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll z = 2 ; z < maxn ; z <<= 1){
		for(ll i = z ; i < maxn ; i += z){
			t[i]++;
		}
	}
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = 2 * i ; j < maxn ; j += i){
			dv[j].push_back(i);
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}