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

const ll maxn = 6e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll f[maxn] , dp[maxn] , lc[maxn] , rc[maxn];
vector<pll> v , pb;
vector<ll> b , c , rb[maxn];

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll l , r;
		cin>>l>>r;
		v.push_back({r , -l});
	}
	v.push_back({1e6 , 1}); n++;
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		ll l = -v[i].second , r = v[i].first;
//		cout<<l<<' '<<r<<'\n';
		b.clear(); pb.clear(); c.clear();
		for(ll j = 0 ; j < n ; j++){
			if(j == i) continue;
			ll lj = -v[j].second , rj = v[j].first;
			if(l <= lj && r >= rj){
				b.push_back(j);
				c.push_back(lj);
				c.push_back(rj);
			}
		}
		sort(all(c));
		c.resize(distance(c.begin() , unique(all(c))));
		ll bs = sze(b) , cs = sze(c);
		for(ll j = 0 ; j < cs ; j++) rb[j].clear();
		for(ll j = 0 ; j < bs ; j++){
			lc[j] = lower_bound(all(c) , -v[b[j]].second) - c.begin();
			rc[j] = lower_bound(all(c) , v[b[j]].first) - c.begin();
			rb[rc[j]].push_back(j);
		}
		for(ll k = 0 ; k < cs ; k++){
			dp[k] = (k ? dp[k - 1] : 0);
			for(auto j : rb[k]){
				dp[k] = max(dp[k] , (lc[j] ? dp[lc[j] - 1] : 0) + f[b[j]]);
			}
		}
		f[i] = dp[cs - 1] + 1;
	}
//	for(ll i = 0 ; i < n ; i++){
//		cout<<f[i]<<' ';
//	}
//	cout<<'\n';
	cout<<f[n - 1] - 1<<'\n';
	return;
}

/*
1
4
1 3
2 3
2 5
4 5
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}