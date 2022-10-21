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

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e18;

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

string s , t;
ll f[maxn] , a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q , m;
	cin>>s>>q; n = sze(s);
	ll ans = 0;
	for(ll e = 0 ; e < q ; e++){
		cin>>t;
		m = sze(t); t += '$';
		if(m == 1) continue;
		f[0] = -1;
		ll g = -1;
		for(ll j = 1 ; j < m ; j++){
			while(true){
				if(t[g + 1] == t[j]){
					g++;
					break;
				}
				if(g == -1) break;
				g = f[g];
			}
			f[j] = g;
		}
		g = -1;
		ll res = 0;
		for(ll i = 0 ; i < n ; i++){
			while(true){
				if(t[g + 1] == s[i]){
					g++;
					break;
				}
				if(g == -1) break;
				g = f[g];
			}
			res = max(res , g + 1);
			a[i] = res;
		}
		t.resize(m); reverse(all(t)); t += '$';
		g = -1;
		for(ll j = 1 ; j < m ; j++){
			while(true){
				if(t[g + 1] == t[j]){
					g++;
					break;
				}
				if(g == -1) break;
				g = f[g];
			}
			f[j] = g;
		}
		bool c = false;
		g = -1;
		for(ll i = n - 1 ; ~i ; i--){
			while(true){
				if(t[g + 1] == s[i]){
					g++;
					break;
				}
				if(g == -1) break;
				g = f[g];
			}
			ll h = (!i ? 0 : a[i - 1]) + g + 1;
			c |= (h >= m);
		}
		ans += c;
	}
	cout<<ans<<'\n';
	return 0;
}