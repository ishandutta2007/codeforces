#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e15;

ll tav(ll n , ll k){
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

ll t[30] , cnt[30] , w;
bitset<30> o;

bool check(ll h){
	ll f = 0;
	for(ll j = 29 ; j >= 0 ; j--){
		f <<= 1;
		if(o[j]) f += h;
		f -= cnt[j];
		if(f < 0) return false;
	}
	return true;
}

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n>>w; o = w;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(ll j = 0 ; j < 20 ; j++){
			if(h == t[j]){
				cnt[j]++;
				break;
			}
		}
	}
	ll l = 0 , r = n + 1;
	while(l < r - 1){
		ll m = (r + l) / 2;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<l + 1<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	t[0] = 1;
	for(ll i = 1 ; i < 30 ; i++){
		t[i] = t[i - 1] << 1;
	}
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}