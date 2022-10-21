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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll val[(maxn << 1)];

struct segtree {

	ll sz = 1;

	void init(ll n){
		while(sz < n) sz <<= 1;
		fill(val , val + (sz << 1) , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(){
		return val[0];
	}

	void clear(){
		sz = 1;
		return;
	}

};

bitset<maxn> gh;

void prime(){
	gh.set();
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = i * i ; j < maxn ; j += i){
			gh[j] = false;
		}
	}
	return;
}

vector<ll> dv[maxn];
ll sum[(maxn << 1)];
ll a[maxn] , st[maxn];
segtree gt;

void solve(){
	gt.clear();
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll o = 0;
	for(auto i : dv[n]){
		st[i] = o; o += i;
	}
	fill(sum , sum + o , 0);
	for(ll i = 0 ; i < n ; i++){
		for(auto j : dv[n]){
			sum[i % j + st[j]] += a[i] * j;
		}
	}
	gt.init(o);
	for(ll i = 0 ; i < o ; i++) gt.set(i , sum[i]);
	cout<<gt.cal()<<'\n';
	for(ll e = 0 ; e < q ; e++){
		ll i , x , d;
		cin>>i>>x; i--;
		d = x - a[i]; a[i] = x;
		for(auto j : dv[n]){
			ll t = i % j + st[j];
			sum[t] += d * j;
			gt.set(t , sum[t]);
		}
		cout<<gt.cal()<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll mx = 0;
	for(ll i = 1 ; i < maxn ; i++){
		mx = max(mx , sze(dv[i]));
		for(ll j = i << 1 ; j < maxn ; j += i){
			if(gh[j / i]) dv[j].push_back(i);
		}
	}
//	cout<<mx<<'\n';
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}