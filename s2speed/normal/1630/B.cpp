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

ll cnt[maxn] , ps[maxn] , a[maxn];
vector<pll> v;

void solve(){
	v.clear();
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		ps[i] = ps[i - 1] + cnt[i];
	}
	ll ans = inf , ind = 1 , lb = (n - k + 1) / 2 + k;
	for(ll i = 1 ; i <= n ; i++){
		if(n - ps[i - 1] < lb) break;
		ll l = 0 , r = n + 1;
		while(l < r - 1){
			ll m = (r + l) >> 1;
			if(ps[m] - ps[i - 1] >= lb){
				r = m;
			} else {
				l = m;
			}
		}
		if(l + 1 - i < ans){
			ans = l + 1 - i;
			ind = i;
		}
	}
	ll h = 0 , ct = 0 , l = ind , r = l + ans , x = 0;
	for(ll i = 0 ; i < n ; i++){
		h += -1 + 2 * (a[i] >= l && a[i] <= r);
		if(h == 1 && ct != k - 1){
			v.push_back({x , i});
			x = i + 1;
			h = 0;
			ct++;
		}
	}
	v.push_back({x , n - 1});
	cout<<l<<' '<<r<<'\n';
	for(ll i = 0 ; i < k ; i++){
		cout<<v[i].first + 1<<' '<<v[i].second + 1<<'\n';
	}
	for(ll i = 0 ; i < n ; i++) cnt[a[i]]--;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}