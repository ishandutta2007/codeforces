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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<ll> v[maxn];
ll a[maxn];

void solve(){
	ll n , d , g;
	cin>>n>>d; g = gcd(n , d);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < g ; i++) v[i].clear();
	for(ll j = 0 ; j < g ; j++){
		ll s = -1;
		bool f = true;
		for(ll i = j ; i != j || f ; i += d , i %= n){
			f = false;
			if(!a[i]){
				s = i;
				break;
			}
		}
		if(s == -1){
			cout<<"-1\n";
			return;
		}
		v[j].push_back(0);
		for(ll i = (s + d) % n ; i != s ; i += d , i %= n){
			v[j].push_back(a[i]);
		}
	}
	ll ans = 0 , vs = sze(v[0]);
	for(ll i = 0 ; i < g ; i++){
		ll cur = 0;
		for(ll j = 0 ; j < vs ; j++){
			if(v[i][j]){
				cur++;
				ans = max(ans , cur);
			} else {
				cur = 0;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}