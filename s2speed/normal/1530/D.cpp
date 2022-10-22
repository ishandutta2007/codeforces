#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
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

vector<ll> cnt[maxn] , v , u;
ll a[maxn] , b[maxn];

void solve(){
	v.clear(); u.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++) cnt[i].clear();
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		cnt[a[i]].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		if(cnt[i].empty()){
			u.push_back(i);
		}
	}
	ll us = sze(u);
	cout<<n - us<<'\n';
	if(us == 0){
		for(ll i = 0 ; i < n ; i++){
			cout<<a[i] + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	if(us == 1){
		for(ll i = 0 ; i < n ; i++){
			if(i == u[0]) continue;
			if(sze(cnt[i]) == 2){
				v.push_back(cnt[i][0]); v.push_back(cnt[i][1]);
			} else {
				b[cnt[i][0]] = i;
			}
		}
		if(v[0] == u[0]){
			b[v[1]] = u[0];
			b[v[0]] = a[v[0]];
		} else {
			b[v[0]] = u[0];
			b[v[1]] = a[v[0]];
		}
		for(ll i = 0 ; i < n ; i++){
			cout<<b[i] + 1<<' ';
		}
		cout<<'\n';
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		ll cs = sze(cnt[i]);
		if(!cs) continue;
		for(ll j = 1 ; j < cs ; j++){
			v.push_back(cnt[i][j]);
		}
		b[cnt[i][0]] = i;
	}
	sort(all(u));
	sort(all(v) , greater<ll>());
	for(ll i = 0 ; i < us ; i++){
		if(v[i] == u[i]){
			if(i){
				swap(v[i] , v[i - 1]);
			} else {
				swap(v[i] , v[i + 1]);
			}
		}
	}
	for(ll i = 0 ; i < us ; i++){
		b[v[i]] = u[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<b[i] + 1<<' ';
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