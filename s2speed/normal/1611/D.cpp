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

ll dis[maxn] , par[maxn] , a[maxn] , w[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>par[i]; par[i]--;
		dis[i] = -1;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	if(par[a[0]] != a[0]){
		cout<<"-1\n";
		return;
	}
	w[a[0]] = dis[a[0]] = 0;
	for(ll i = 1 ; i < n ; i++){
		if(dis[par[a[i]]] == -1){
			cout<<"-1\n";
			return;
		}
		dis[a[i]] = i;
		w[a[i]] = i - dis[par[a[i]]];
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<w[i]<<' ';
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