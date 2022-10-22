#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

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

ll sf[maxn] , a[maxn];

void solve(){
	ll n , q;
	string s;
	cin>>n>>q>>s;
	sf[n] = 0;
	for(ll i = n - 1 ; i >= 0 ; i--){
		ll h = (s[i] == '+') ^ (i & 1);
		if(!h) h--;
		a[i] = h;
		sf[i] = sf[i + 1] + h;
	}
	for(ll i = 0 ; i < q ; i++){
		ll l , r;
		cin>>l>>r; l--;
		ll h = sf[l] - sf[r];
		if(h == 0){
			cout<<"0\n";
			continue;
		}
		cout<<2 - ((r - l) & 1)<<'\n';
		if(!((r - l) & 1)){
			cout<<r--<<' ';
		}
		h = sf[l] - sf[r];
		bool c = (h < 0);
		if(c) h = -h;
		ll bl = l , br = r , t = (h + 1) / 2;
		if(c){
			t = -t;
			h = -h;
		}
		t += sf[r];
		while(bl < br - 1){
			ll m = (bl + br) / 2;
			if(sf[m] == t && sf[m + 1] == t + (c ? 1 : -1)){
				bl = m;
				break;
			}
			if(c){
				if(sf[m] <= t){
					bl = m;
				} else {
					br = m;
				}
			} else {
				if(sf[m] >= t){
					bl = m;
				} else {
					br = m;
				}
			}
		}
		cout<<bl + 1<<'\n';
	}
	return;
}

/*
1
14 1
+--++---++-++-
1 14
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}