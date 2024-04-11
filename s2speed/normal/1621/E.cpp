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
typedef pair<db , ll> pdl;
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

vector<ll> a;
vector<ll> b[maxn];
ll sum[maxn] , k[maxn] , c[maxn] , ps[maxn] , pd[maxn] , pu[maxn];
db r[maxn];
vector<pdl> v;

void solve(){
	a.clear(); v.clear();
	ll n , m;
	cin>>m>>n;
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h;
		a.push_back(h);
	}
	sort(all(a) , greater<ll>()); a.resize(n); reverse(all(a));
	for(ll i = 0 ; i < n ; i++){
		b[i].clear();
		sum[i] = 0;
		cin>>k[i];
		for(ll j = 0 ; j < k[i] ; j++){
			ll h;
			cin>>h;
			b[i].push_back(h);
			sum[i] += h;
		}
		db h = (db)sum[i] / k[i];
		v.push_back(mp(h , i));
		r[i] = h;
	}
	sort(all(v));
	for(ll i = 0 ; i < n ; i++){
		c[v[i].second] = i;
	}
	ps[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + (v[i].first > a[i - 1]);
	}
	pd[n - 1] = 0;
	for(ll i = n - 2 ; i >= 0 ; i--){
		pd[i] = pd[i + 1] + (v[i].first > a[i + 1]);
	}
	pu[0] = (v[0].first > a[0]);
	for(ll i = 1 ; i < n ; i++){
		pu[i] = pu[i - 1] + (v[i].first > a[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < k[i] ; j++){
			db h = (db)(sum[i] - b[i][j]) / (k[i] - 1);
			ll q = lower_bound(all(v) , mp(h , inf)) - v.begin() - (h >= r[i]);
			bool ans;
			if(q >= c[i]){
				ans = (ps[q] == ps[c[i]]) && ((c[i] == 0 ? 0 : pu[c[i] - 1]) == 0) && (pu[q] == pu[n - 1]) && (h <= a[q]);
			} else {
				ans = (pd[q] == pd[c[i]]) && ((q == 0 ? 0 : pu[q - 1]) == 0) && (pu[c[i]] == pu[n - 1]) && (h <= a[q]);
			}
			cout<<ans;
		}
	}
	cout<<'\n';
	return;
}

/*
1
4 2
9 12 12 6
2
4 5
3
111 11 11
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}