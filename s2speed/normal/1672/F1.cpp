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

vector<ll> ind[maxn] , v[maxn];
ll a[maxn] , cnt[maxn] , ans[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ind[i].clear();
		v[i].clear();
		cnt[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		ind[a[i]].push_back(i);
		cnt[a[i]]++;
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < cnt[i] ; j++){
			v[j].push_back(ind[i][j]);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(v[i].empty()) break;
		ll vs = sze(v[i]);
		for(ll j = 0 ; j < vs - 1 ; j++){
			ans[v[i][j]] = a[v[i][j + 1]];
		}
		ans[v[i][vs - 1]] = a[v[i][0]];
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i] + 1<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}