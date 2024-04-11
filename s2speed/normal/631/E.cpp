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

ll intr(ll a , ll b , ll c , ll d){
	ll q = a - c , w = d - b;
	w += (1 - ((w < 0) << 1));
	return w / q;
}

ll a[maxn] , b[maxn] , ps[maxn];
vector<pll> v , u;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	ll res = 0 , ans = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		u.push_back({a[i] , i});
		ans += 1ll * i * a[i];
	}
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	sort(all(u));
	for(ll e = 0 ; e < n ; e++){
		ll i = u[e].second;
		b[i] = 1ll * -i * a[i] + ps[i];
		ll t = 0;
		bool f = true;
		while(!v.empty()){
			ll x = v.back().first , j = v.back().second;
			if(a[j] == a[i]){
				if(b[j] > b[i]){
					f = false;
					break;
				} else {
					v.pop_back();
					continue;
				}
			}
			ll h = intr(a[i] , b[i] , a[j] , b[j]);
			if(h > x){
				t = h;
				break;
			}
			v.pop_back();
		}
		if(t <= n && f) v.push_back({t , i});
	}
	for(ll i = 0 ; i <= n ; i++){
		ll j = upper_bound(all(v) , mp(i , inf)) - v.begin() - 1; j = v[j].second;
		ll h = 1ll * a[j] * i + b[j] - ps[i];
		res = max(res , h);
	}
	cout<<ans + res<<'\n';
	return 0;
}