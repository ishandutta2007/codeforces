#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll ans[maxn] , x[maxn];
vector<plll> a[2];
vector<pll> v , u , w , t;

void solve(){
	a[0].clear(); a[1].clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		ans[i] = -1;
		cin>>x[i];
	}
	for(ll i = 0 ; i < n ; i++){
		char c;
		cin>>c;
		a[x[i] & 1].push_back({{x[i] , i} , (c == 'R')});
	}
	for(ll c = 0 ; c < 2 ; c++){
		v.clear(); u.clear(); w.clear(); t.clear();
		for(auto q : a[c]){
			if(q.second == 0){
				v.push_back(q.first);
			} else {
				u.push_back(q.first);
			}
		}
		sort(all(v));
		sort(all(u));
		ll x = 0 , vs = sze(v) , us = sze(u);
		for(ll i = 0 ; i < vs ; i++){
			while(x < us){
				if(u[x].first > v[i].first) break;
				w.push_back(u[x++]);
			}
			if(w.empty()){
				t.push_back(v[i]);
			} else {
				ans[w.back().second] = ans[v[i].second] = (v[i].first - w.back().first) / 2;
				w.pop_back();
			}
		}
		while(x < us){
			w.push_back(u[x++]);
		}
		ll ws = sze(w) , ts = sze(t);
		for(ll i = ws - 1 ; i > 0 ; i -= 2){
			ans[w[i].second] = ans[w[i - 1].second] = m - w[i].first + (w[i].first - w[i - 1].first) / 2;
		}
		for(ll i = 0 ; i + 1 < ts ; i += 2){
			ans[t[i].second] = ans[t[i + 1].second] = t[i].first + (t[i + 1].first - t[i].first) / 2;
		}
		if(ws & 1 && ts & 1){
			ll o = w[0].first , h = t[ts - 1].first , r = 0;
			r = h;
			o += h;
			h = 0;
			bool ch = true;
			if(o > m){
				ch = false;
				o = 2 * m - o;
			}
			if(ch){
				r += m - o;
				h += m - o;
				o = m;
			}
			r += (o - h) / 2;
			ans[w[0].second] = ans[t[ts - 1].second] = r;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}