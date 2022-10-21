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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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

struct segtree {

	ll sz = 1;
	vector<ll> val , cnt;

	void init(ll n){
		while(sz < n) sz <<= 1;
		val.assign(sz << 1 , 0);
		cnt.assign(sz << 1 , 0);
		return;
	}

	void set(ll i , ll k , ll x , ll lx , ll rx){
		if(rx - lx == 1){
			val[x] = k;
			cnt[x] = 1;
			return;
		}
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		if(i < m){
			set(i , k , ln , lx , m);
		} else {
			set(i , k , rn , m , rx);
		}
		val[x] = max(val[ln] , val[rn]);
		cnt[x] = cnt[ln] + cnt[rn];
		return;
	}

	void set(ll i , ll k){
		set(i , k , 0 , 0 , sz);
		return;
	}

	ll cal(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return cnt[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cal(l , r , ln , lx , m);
		b = cal(l , r , rn , m , rx);
		return a + b;
	}

	ll cal(ll l , ll r){
		if(l >= r) return 0;
		return cal(l , r , 0 , 0 , sz);
	}

	ll cad(ll l , ll r , ll x , ll lx , ll rx){
		if(rx <= l || lx >= r) return 0;
		if(rx <= r && lx >= l) return val[x];
		ll m = (rx + lx) >> 1 , ln = (x << 1) + 1 , rn = ln + 1;
		ll a , b;
		a = cad(l , r , ln , lx , m);
		b = cad(l , r , rn , m , rx);
		return max(a , b);
	}

	ll cad(ll l , ll r){
		return cad(l , r , 0 , 0 , sz);
	}

	void clear(){
		sz = 1;
		val.clear();
		cnt.clear();
	}

};

segtree st[maxn];
vector<ll> a[maxn] , v;
vector<pll> u;
ll cnt[maxn] , dp[maxn];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		a[i].clear();
		a[i].resize(m);
		st[i].clear();
		st[i].init(m);
	}
	for(ll i = 0 ; i < n ; i++){
		v.clear();
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			v.push_back(a[i][j]);
		}
		sort(all(v));
		v.resize(distance(v.begin() , unique(all(v))));
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = lower_bound(all(v) , a[i][j]) - v.begin();
		}
	}
	ll I = -1 , J = -1;
	for(ll i = 0 ; i < n ; i++){
		u.clear();
		for(ll j = 0 ; j < m ; j++){
			u.push_back({a[i][j] , j});
		}
		sort(all(u));
		ll res = 0;
		for(auto p : u){
			ll j = p.second;
			cnt[j] = st[i].cal(j , m);
			dp[j] = st[i].cad(j , m) + 1;
			res = max(res , dp[j]);
			st[i].set(j , dp[j]);
		}
		if(res >= 4){
			cout<<"-1\n";
			return;
		}
		if(res == 1) continue;
		if(res == 3){
			ll i1 , i2 , i3 , s = inf , j = 0;
			for( ; j < m ; j++){
				if(dp[j] == 3){
					i1 = j;
					s = a[i][j++];
					break;
				}
			}
			for( ; j < m ; j++){
				if(dp[j] == 2 && a[i][j] < s){
					i2 = j;
					s = a[i][j++];
					break;
				}
			}
			for( ; j < m ; j++){
				if(dp[j] == 1 && a[i][j] < s){
					i3 = j++;
					break;
				}
			}
			I = i1; J = i3;
			break;
		}
		ll ij = -1;
		for(ll j = 0 ; j < m ; j++){
			if(cnt[j] > 0){
				ij = j;
				break;
			}
		}
		I = ij;
		ll mx = -1;
		for(ll j = 0 ; j < m ; j++){
			if(a[i][I] > a[i][j]){
				J = j;
			}
		}
		break;
	}
	if(I == -1){
		cout<<"1 1\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		swap(a[i][I] , a[i][J]);
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 1 ; j < m ; j++){
			if(a[i][j] < a[i][j - 1]){
				cout<<"-1\n";
				return;
			}
		}
	}
	cout<<I + 1<<' '<<J + 1<<'\n';
	return;
}

/*
1
2 3
6 2 1
5 4 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}